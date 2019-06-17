const int buttonPin = 2;
const int buttonPin2 = 4;
const int led = 13;
const int led2 = 12;

boolean timedOut = false;
int previousReading;
int previousReading2;
int counter = 0;

unsigned long timeSinceStart;
unsigned long timer;
unsigned long INTERVAL = 5010;

void setup() {
  pinMode(buttonPin, INPUT);
  pinMode(buttonPin2, INPUT);
  pinMode(led, OUTPUT);
  pinMode(led2, OUTPUT);
  Serial.begin(9600);
  timedOut = false;
  timer = millis();
  counter = 0;
  previousReading = digitalRead(buttonPin);
  previousReading2 = digitalRead(buttonPin2);
}

void loop() {
  int reading = digitalRead(buttonPin);
  int reading2 = digitalRead(buttonPin2);
  // If the reading used to be LOW and is now HIGH, that marks the transition of a button being pushed
  // a transition of HIGH to LOW would indicate the button being released, but that's not what we're counting here
  if (previousReading == LOW && reading == HIGH) {
    counter++;
    Serial.print("Time: ");
    timeSinceStart = millis();
    Serial.print(timeSinceStart);
    Serial.print("     Button pressed ");
    Serial.print(counter);
    Serial.println(" times");
    digitalWrite(led, HIGH);
  }
  if (previousReading2 == LOW && reading2 == HIGH) {
   for (counter; counter >= 0; counter--) {
    if ((!timedOut) && ((millis() - timer)) > INTERVAL) {
     timedOut = true;
     timer += INTERVAL;
     if (digitalRead(led)) {
       digitalWrite(led, LOW);
     } else {
       digitalWrite(led, HIGH);
     }
    }
   }
  }
  previousReading = reading;
  previousReading2 = reading2;
}







