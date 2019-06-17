const int buttonPin = 0;
int buttonState = 0;
int Row1 = 1;
int Row2 = 2;
int Row3 = 3;
int Row4 = 4;
int Row5 = 5;
int Row6 = 6;
int Row7 = 7;
int Row8 = 8;
int RSerial = 9;
int BSerial = 10;
int GSerial = 11;
int RCLK = 12;
int SCLK = 13;
int forLoop = 0;
int state = 0;

/*
248, 36, 34, 36, 248, 0, 0,    // A
*/

int drawThisPlsRed[] =
{
0,
0, 62, 96, 192, 96, 62, 0, 0,  // V
130, 254, 130, 0, 0,           // I
254, 130, 130, 124, 0, 0,      // D
254, 146, 146, 146, 0, 0,      // E
254, 12, 16, 96, 254, 0, 0,    // N
254, 130, 130, 124, 0, 0,      // D
66, 130, 130, 126, 0, 0,       // J
126, 128, 128, 126, 0, 0,      // U
254, 18, 50, 82, 140, 0, 0,    // R  
158, 146, 146, 242, 0, 0,      // S
16, 16, 16, 0, 0,              // BIG LINE
//  254, 16, 16, 254, 0, 0,        // H
//  2, 2, 254, 2, 2, 0, 0,         // T
//  130, 108, 16, 108, 130, 0, 0,  // X
//  16, 16, 16, 0, 0,              // BIG LINE
124, 130, 130, 146, 112, 0, 0, // G
248, 36, 34, 36, 248, 0, 0,    // A
254, 4, 8, 4, 254, 0, 0,       // M
254, 146, 146, 146, 0, 0,      // E
124, 130, 130, 130, 68, 0, 0,  // C
124, 130, 130, 130, 124, 0, 0, // O
254, 128, 128, 128, 0, 0,      // L
254, 128, 128, 128, 0, 0,      // L 
254, 146, 146, 146, 0, 0,      // E
124, 130, 130, 146, 112, 0, 0, // G
254, 146, 146, 146, 0, 0,      // E
//  16, 16, 16, 0, 0,              // BIG LINE
//  254, 146, 146, 146, 0, 0,      // E
//  254, 128, 128, 128, 0, 0,      // L
//  2, 2, 254, 2, 2, 0, 0,         // T
//  254, 146, 146, 146, 0, 0,      // E
//  254, 24, 36, 66, 130, 0, 0,    // K
0,0,0,0,0,0,0               // Empty  
};

int drawThisPlsBlue[] =
{
0,0,0,0,0,0,0,        // V
0, 0, 0, 0,           // I
0, 0, 0, 0, 0,      // D
0, 0, 0, 0, 0,      // E
0, 0, 0, 0, 0, 0,    // N
0, 0, 0, 0, 0,      // D
0, 0, 0, 0, 0,       // J
0, 0, 0, 0, 0,      // U
0, 0, 0, 0, 0, 0,    // R  
0, 0, 0, 0, 0,      // S
0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,0,0,
0,0,0,0,0,0,0,
0,0,0,0,0,0,0,
0,0,0,0,0,0,0,
0,0,0,0,0,0,0,
0,0,0,0,0,0,0,
0,0,0,0,0,0,0,
0,0,0,0,0,0,0,
0,0,0,0,0,0,0,
0,0,0,0,0,0,0,
0,0,0,0,0,0,0,
0,0,0,0,0,0,0,
0,0,0,0,0,0,0,
0,0,0,0,0,0,0,
0,0,0,0,0,0,0,
0,0,0,0,0,0,0,
0,0,0,0,0,0,0,
0,0,0,0,0,0,0,
0,0,0,0,0,0,0,
0,0,0,0,0,0,0,
0,0,0,0,0,0,0,
};

int drawThisPlsGreen[] =
{
0,0,0,0,0,0,0,        // V
0, 0, 0, 0,           // I
0, 0, 0, 0, 0,      // D
0, 0, 0, 0, 0,      // E
0, 0, 0, 0, 0, 0,    // N
0, 0, 0, 0, 0,      // D
0, 0, 0, 0, 0,       // J
0, 0, 0, 0, 0,      // U
0, 0, 0, 0, 0, 0,    // R  
0, 0, 0, 0, 0,      // S
0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,0,0,
0,0,0,0,0,0,0,
0,0,0,0,0,0,0,
0,0,0,0,0,0,0,
0,0,0,0,0,0,0,
0,0,0,0,0,0,0,
0,0,0,0,0,0,0,
0,0,0,0,0,0,0,
0,0,0,0,0,0,0,
0,0,0,0,0,0,0,
0,0,0,0,0,0,0,
0,0,0,0,0,0,0,
0,0,0,0,0,0,0,
0,0,0,0,0,0,0,
0,0,0,0,0,0,0,
0,0,0,0,0,0,0,
0,0,0,0,0,0,0,
0,0,0,0,0,0,0,
0,0,0,0,0,0,0,
0,0,0,0,0,0,0,
};

byte green[8];
byte red[8];
byte blue[8];

int startAnim = 0; 
int counting = 0;
bool _isCounting = false;
bool intervalChange = false;

// Set up arrays, select one of these three things to display
#include <elapsedMillis.h>

//DEFAULT
byte Bbitmap [8]={0,0,0,0,0,0,0,0};
byte Gbitmap [8]={0,0,0,0,0,0,0,0};
byte Rbitmap [8]={0,0,0,0,0,0,0,0};
// RGB Flag
//byte Bbitmap [8]={240, 240, 240, 240, 0, 0, 0, 0};
//byte Gbitmap [8]={15, 0, 15, 0, 255, 0, 255, 0};
//byte Rbitmap [8]={0, 15, 0, 15, 0, 255, 0, 255};
// Blue Face
//byte Bbitmap [8]={60, 126, 255, 219, 255, 219, 102, 60};
//byte Gbitmap [8]={60, 126, 129, 165, 129, 129,   0,  0};
//byte Rbitmap [8]={60, 126,   0,  36,   0,  36,  24,  0};
// Red Car
//byte Gbitmap [8]={8, 0, 0, 0, 0, 0, 255, 255};
//byte Bbitmap [8]={255, 255, 255, 131, 0, 0, 0, 0};
//byte Rbitmap [8]={8, 0, 0, 124, 255, 189, 0, 0};
#include <elapsedMillis.h>  
unsigned int interval = 100;
// Set the pins to output to the array
void setup() {
_isCounting = false;
counting = 1;
startAnim = 0;
pinMode(buttonPin, INPUT);
pinMode(Row1, OUTPUT);
pinMode(Row2, OUTPUT);
pinMode(Row3, OUTPUT);
pinMode(Row4, OUTPUT);
pinMode(Row5, OUTPUT);
pinMode(Row6, OUTPUT);
pinMode(Row7, OUTPUT);
pinMode(Row8, OUTPUT);
pinMode(BSerial, OUTPUT);
pinMode(GSerial, OUTPUT);
pinMode(RSerial, OUTPUT);
pinMode(RCLK, OUTPUT);
pinMode(SCLK, OUTPUT);
buttonState == LOW;
intervalChange = true;
//  Serial.begin(9600);
}

elapsedMillis elapsedTime;

void loop() {

    byte Gbitmap [8]={green[0], green[1], green[2], green[3], green[4], green[5], green[6], green[7]};
    byte Bbitmap [8]={blue[0], blue[1], blue[2], blue[3], blue[4], blue[5], blue[6], blue[7]};
    byte Rbitmap [8]={red[0], red[1], red[2], red[3], red[4], red[5], red[6], red[7]};

    for (int row = 0; row <8; row++){
        //turn everything off
        digitalWrite (Row1, LOW);
        digitalWrite (Row2, LOW);
        digitalWrite (Row3, LOW);
        digitalWrite (Row4, LOW);
        digitalWrite (Row5, LOW);
        digitalWrite (Row6, LOW);
        digitalWrite (Row7, LOW);
        digitalWrite (Row8, LOW);
        // set up the data in the shift registers
        for (int shiftbit = 0; shiftbit <8; shiftbit++){
            digitalWrite(BSerial, HIGH);
            digitalWrite(GSerial, HIGH);
            digitalWrite(RSerial, HIGH);
            if bitRead(Bbitmap[row],shiftbit) digitalWrite(BSerial, LOW);
            if bitRead(Gbitmap[row],shiftbit) digitalWrite(GSerial, LOW);
            if bitRead(Rbitmap[row],shiftbit) digitalWrite(RSerial, LOW);
            digitalWrite(SCLK, LOW);
            digitalWrite(SCLK, HIGH);
        }
        //latch the data
        digitalWrite(RCLK, HIGH);
        digitalWrite(RCLK, LOW); 
        // turn on the associated row
        if (row == 0) digitalWrite (Row1, HIGH);
        if (row == 1) digitalWrite (Row2, HIGH); 
        if (row == 2) digitalWrite (Row3, HIGH); 
        if (row == 3) digitalWrite (Row4, HIGH); 
        if (row == 4) digitalWrite (Row5, HIGH); 
        if (row == 5) digitalWrite (Row6, HIGH); 
        if (row == 6) digitalWrite (Row7, HIGH); 
        if (row == 7) digitalWrite (Row8, HIGH);
        delay(2);  
    }  

    buttonState = digitalRead(buttonPin);
    if (buttonState == LOW) {
        startAnim = true;
        _isCounting = true;
    }
    if (startAnim == true && _isCounting == true) {
        if (counting == 1) {
            intervalChange = false;
        }

        if (counting > (sizeof(drawThisPlsRed)/sizeof(int))) {
            state ++;
            if (state >= 6)
            {
            state = 0;
            }
            
            counting = 1;
        }

        if (intervalChange) {

            setRed();

            if (state == 0) {
                blue[7] = drawThisPlsRed[counting -1];
                /*blue[7] = drawThisPlsBlue[counting -1];
                green[7] = drawThisPlsGreen[counting -1];
            
                blue[7] =drawThisPlsRed[counting -1];
                green[7] =drawThisPlsRed[counting -1];
                */ 
            }
            else if ( state == 1) {
                blue[7] = drawThisPlsRed[counting -1];
                green[7] = drawThisPlsRed[counting -1];
            }
            else if ( state == 2) {
                green[7] = drawThisPlsRed[counting -1];
            }
            else if ( state == 3) {
                green[7] = drawThisPlsRed[counting -1];
                red[7] = drawThisPlsRed[counting -1];
            }
            else if ( state == 4) {
                red[7] = drawThisPlsRed[counting -1];
            }
            else if ( state == 5) {
                blue[7] = drawThisPlsRed[counting -1];
                red[7] = drawThisPlsRed[counting -1];
            }
            


        }
        elapsedmillisloop();
    } 
}

void setRed () {
        intervalChange = false;
        red[0] = red[1];
        red[1] = red[2];
        red[2] = red[3];
        red[3] = red[4];
        red[4] = red[5];
        red[5] = red[6];
        red[6] = red[7];

        blue[0] = blue[1];
        blue[1] = blue[2];
        blue[2] = blue[3];
        blue[3] = blue[4];
        blue[4] = blue[5];
        blue[5] = blue[6];
        blue[6] = blue[7];

        green[0] = green[1];
        green[1] = green[2];
        green[2] = green[3];
        green[3] = green[4];
        green[4] = green[5];
        green[5] = green[6];
        green[6] = green[7];

        
}

void elapsedmillisloop() {
    if (startAnim = true) 
    {
        if (elapsedTime > interval) 
        {
        counting++;
        intervalChange = true;

        elapsedTime = 0;
        }
    }
}
