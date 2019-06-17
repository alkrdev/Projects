

#define BAUDRATE  115200
//#define BAUDRATE  9600

#define NELEM(x)  (sizeof(x) / sizeof((x)[0]))

static uint8_t freqidx;   /* Current frequency; index in frequency table */
static uint8_t duty;    /* Duty-cycle in percent [0...100] */
static uint8_t quiet;   /* Set if quiet mode enabled */

typedef struct __freqtable_t {
  uint32_t  freq;   /* Frequency in Hz */
  uint16_t  tmrtop;   /* Timer TOP value */
  uint8_t   tccr1b;   /* Prescaler setup + rest of control register */
} freqtable_t;


/* Actual table of selectable frequencies (in flash) */
static const freqtable_t freqs[] PROGMEM = {
  { 1000000,     8, _BV(WGM13) | _BV(CS10) },
  {  500000,    16, _BV(WGM13) | _BV(CS10) },
  {  200000,    32, _BV(WGM13) | _BV(CS10) },
  {  100000,    80, _BV(WGM13) | _BV(CS10) },
  {   50000,   160, _BV(WGM13) | _BV(CS10) },
  {   20000,   320, _BV(WGM13) | _BV(CS10) },
  {   10000,   800, _BV(WGM13) | _BV(CS10) },
  {    5000,  1600, _BV(WGM13) | _BV(CS10) },
  {    2000,  3200, _BV(WGM13) | _BV(CS10) },
  {    1000,  8000, _BV(WGM13) | _BV(CS10) },
  {     500, 16000, _BV(WGM13) | _BV(CS10) },
  {     200, 32000, _BV(WGM13) | _BV(CS10) },
  {     100, 10000, _BV(WGM13) | _BV(CS11) },
  {      50, 20000, _BV(WGM13) | _BV(CS11) },
  {      20,  5000, _BV(WGM13) | _BV(CS11) | _BV(CS10) },
  {      10, 12500, _BV(WGM13) | _BV(CS11) | _BV(CS10) },
  {       5, 25000, _BV(WGM13) | _BV(CS11) | _BV(CS10) },
  {       2, 50000, _BV(WGM13) | _BV(CS11) | _BV(CS10) },
  {       1, 31500, _BV(WGM13) | _BV(CS12) },
};

#define F_1K  9 /* Index for 1kHz */
#define F_100K  3 /* Index for 100kHz */

static void showfreq(void)
{
  if(quiet)
    return;

  /* Print the new value(s) to console */
  Serial.print(pgm_read_dword(&freqs[freqidx].freq));
  Serial.write("Hz @ ");
  Serial.print(duty);
  Serial.write("%");
  /* At high frequency, we cannot control the duty-cycle accurately */
  if(freqidx < F_100K)
    Serial.write(" (reduced duty-cycle control)");
  Serial.write("\r\n");
}

static void showhelp(void)
{
  /* Blabla */
  if(quiet)
    return;
  Serial.write("Frequency Synthesizer 1Hz...1MHz\r\n");
  Serial.write(" + or F    Increase frequency\r\n");
  Serial.write(" - or f    Decrease frequency\r\n");
  Serial.write(" D         Increase duty-cycle\r\n");
  Serial.write(" d         Decrease duty-cycle\r\n");
  Serial.write(" Q         Enable quiet mode\r\n");
  Serial.write(" q         Disable quiet mode\r\n");
  Serial.write(" h or H    This help screen\r\n");
}

/* Recalculate the timer and PWM settings */
static void recalc(void)
{
  uint16_t tmp;
  uint16_t top;

  /* Setup new timer clock divider for selected frequency */
  TCCR1B = pgm_read_byte(&freqs[freqidx].tccr1b);

  /* Get the timer value for exact frequency and set timer TOP */
  top = pgm_read_word(&freqs[freqidx].tmrtop);
  cli();
  ICR1H = top >> 8;
  ICR1L = top & 0xff;
  sei();

  /* Calculate duty-cycle point in timer for PWM value */
  tmp = (uint32_t)top * duty / 100UL;

  /* Don't let the signal disappear on low/high duty-cycle bounds */
  if(!tmp)
    tmp = 1;
  else if(tmp >= top)
    tmp = top - 1;

  /* Set the PWM trigger points */
  cli();
  OCR1AH = tmp >> 8;  /* Non-inverting output */
  OCR1AL = tmp & 0xff;
  OCR1BH = tmp >> 8;  /* Invertng output */
  OCR1BL = tmp & 0xff;
  sei();

  showfreq();
}

/* Initialization */
void setup()
{
  duty = 50;    /* Start with 50% duty-cycle */
  freqidx = F_1K;   /* Setup 1kHz start frequency */
  quiet = 0;    /* Don't be quiet at start */

  PORTB = 0xff;   /* Ensure enable pull-ups on input ports */
  PORTC = 0xff;
  PORTD = 0xff;

  Serial.begin(BAUDRATE); /* Console interactive for control */
  pinMode(9, OUTPUT); /* OCR1A as output */
  pinMode(10, OUTPUT);  /* OCR1B as output */

  /* Setup timer1 to do phase and frequency correct PWM */
  TCCR1A = _BV(COM1A1) | _BV(COM1B1) | _BV(COM1B0);
  TCCR1B = _BV(WGM13) | _BV(CS10);
  TCCR1C = 0x00;

}

/* Main program */
void loop()
{
  showhelp(); /* Blabla */
  recalc(); /* Ensure initial frequency output */

  /* Loop with console input for interaction (modifying frequency, duty-cycle, etc.) */
  while(1) {
    if(Serial.available() > 0) {
      switch(Serial.read()) {
      case '+':
      case 'F':
        if(freqidx > 0) {
          freqidx--;
          recalc();
        }
        break;
      case '-':
      case 'f':
        if(freqidx < NELEM(freqs)-1) {
          freqidx++;
          recalc();
        }
        break;
      case 'D':
        if(duty < 95) {
          duty += 5;
          recalc();
        }
        break;
      case 'd':
        if(duty > 5) {
          duty -= 5;
          recalc();
        }
        break;
      case 'q':
        quiet = 0;
        break;
      case 'Q':
        quiet = 1;
        break;
      case 'h':
      case 'H':
        showhelp();
        /* Fallthrough */
      default:
        showfreq();
        break;
      }
    }
  }
}

