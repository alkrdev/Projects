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
unsigned int interval = 300;
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
       if (startAnim == true && _isCounting == true)
        {
          if (counting == 1)
           {
            intervalChange = false;
            red[0] = 0;
           }
          if (counting == 2 && intervalChange)
           {
            intervalChange = false;
            red[0] = 0;
            red[1] = 0;
            red[2] = 0;
            red[3] = 0;
            red[4] = 0;
            red[5] = 0;
            red[6] = 0;
            red[7] = 62;
            }
          if (counting == 3 && intervalChange)
           {
            intervalChange = false;
            red[0] = 0;
            red[1] = 0;
            red[2] = 0;
            red[3] = 0;
            red[4] = 0;
            red[5] = 0;
            red[6] = 62;
            red[7] = 96;
            }
          if (counting == 5 && intervalChange)
           {
            intervalChange = false;
            red[0] = 0;
            red[1] = 0;
            red[2] = 0;
            red[3] = 0;
            red[4] = 0;
            red[5] = 62;
            red[6] = 96;
            red[7] = 192;
            }
          if (counting == 6 && intervalChange)
           {
            intervalChange = false;
            red[0] = 0;
            red[1] = 0;
            red[2] = 0;
            red[3] = 0;
            red[4] = 62;
            red[5] = 96;
            red[6] = 192;
            red[7] = 96;
            }
          if (counting == 7 && intervalChange)
           {
            intervalChange = false;
            red[0] = 0;
            red[1] = 0;
            red[2] = 0;
            red[3] = 62;
            red[4] = 96;
            red[5] = 192;
            red[6] = 96;
            red[7] = 62;
            }
          if (counting == 8 && intervalChange)
           {
            intervalChange = false;
            red[0] = 0;
            red[1] = 0;
            red[2] = 62;
            red[3] = 96;
            red[4] = 192;
            red[5] = 96;
            red[6] = 62;
            red[7] = 0;
            }
          if (counting == 9 && intervalChange)
           {
            intervalChange = false;
            red[0] = 0;
            red[1] = 62;
            red[2] = 96;
            red[3] = 192;
            red[4] = 96;
            red[5] = 62;
            red[6] = 0;
            red[7] = 130;
            }
          if (counting == 10 && intervalChange)
           {
            intervalChange = false;
            red[0] = 62;
            red[1] = 96;
            red[2] = 192;
            red[3] = 96;
            red[4] = 62;
            red[5] = 0;
            red[6] = 130;
            red[7] = 254;
            }
          if (counting == 11 && intervalChange)
           {
            intervalChange = false;
            red[0] = 96;
            red[1] = 192;
            red[2] = 96;
            red[3] = 62;
            red[4] = 0;
            red[5] = 130;
            red[6] = 254;
            red[7] = 130;
            }
          if (counting == 12 && intervalChange)
           {
            intervalChange = false;
            red[0] = red[1];
            red[1] = red[2];
            red[2] = red[3];
            red[3] = red[4];
            red[4] = red[5];
            red[5] = red[6];
            red[6] = red[7];
            red[7] = 0;
            }
          if (counting == 13 && intervalChange)
           {
            intervalChange = false;
            red[0] = red[1];
            red[1] = red[2];
            red[2] = red[3];
            red[3] = red[4];
            red[4] = red[5];
            red[5] = red[6];
            red[6] = red[7];
            red[7] = 254;
            }
          if (counting == 14 && intervalChange)
           {
            intervalChange = false;
            red[0] = red[1];
            red[1] = red[2];
            red[2] = red[3];
            red[3] = red[4];
            red[4] = red[5];
            red[5] = red[6];
            red[6] = red[7];
            red[7] = 130;
            }
          if (counting == 15 && intervalChange)
           {
            intervalChange = false;
            red[0] = red[1];
            red[1] = red[2];
            red[2] = red[3];
            red[3] = red[4];
            red[4] = red[5];
            red[5] = red[6];
            red[6] = red[7];
            red[7] = 130;
            }
          if (counting == 16 && intervalChange)
           {
            intervalChange = false;
            red[0] = red[1];
            red[1] = red[2];
            red[2] = red[3];
            red[3] = red[4];
            red[4] = red[5];
            red[5] = red[6];
            red[6] = red[7];
            red[7] = 124;
            }
          if (counting == 17 && intervalChange)
           {
            intervalChange = false;
            red[0] = red[1];
            red[1] = red[2];
            red[2] = red[3];
            red[3] = red[4];
            red[4] = red[5];
            red[5] = red[6];
            red[6] = red[7];
            red[7] = 0;
            }
          if (counting == 18 && intervalChange)
           {
            setRed();
            red[7] = 254;
            }
          if (counting == 19 && intervalChange)
           {
            setRed();
            red[7] = 146;
            }
          if (counting == 19 && intervalChange)
           {
            setRed();
            red[7] = 146;
            }
          if (counting == 20 && intervalChange)
           {
            setRed();
            red[7] = 146;
            }
          if (counting == 21 && intervalChange)
           {
            setRed();
            red[7] = 0;
            }
          if (counting == 22 && intervalChange)
           {
            setRed();
            red[7] = 254;
            }
          if (counting == 23 && intervalChange)
           {
            setRed();
            red[7] = 12;
            }
          if (counting == 24 && intervalChange)
           {
            setRed();
            red[7] = 16;
            }
          if (counting == 25 && intervalChange)
           {
            setRed();
            red[7] = 96;
            }
          if (counting == 26 && intervalChange)
           {
            setRed();
            red[7] = 254;
            }
          if (counting == 27 && intervalChange)
           {
            setRed();
            red[7] = 0;
            }
          if (counting == 28 && intervalChange)
           {
            setRed();
            red[7] = 254;
            }
          if (counting == 29 && intervalChange)
           {
            setRed();
            red[7] = 130;
            }
          if (counting == 30 && intervalChange)
           {
            setRed();
            red[7] = 130;
            }
          if (counting == 31 && intervalChange)
           {
            setRed();
            red[7] = 124;
            }
          if (counting == 32 && intervalChange)
           {
            setRed();
            red[7] = 0;
            }
          if (counting == 33 && intervalChange)
           {
            setRed();
            red[7] = 66;
            }
          if (counting == 34 && intervalChange)
           {
            setRed();
            red[7] = 130;
            }
          if (counting == 35 && intervalChange)
           {
            setRed();
            red[7] = 130;
            }
          if (counting == 36 && intervalChange)
           {
            setRed();
            red[7] = 130;
            }
          if (counting == 37 && intervalChange)
           {
            setRed();
            red[7] = 126;
            }
          if (counting == 38 && intervalChange)
           {
            setRed();
            red[7] = 0;
            }
          if (counting == 39 && intervalChange)
           {
            setRed();
            red[7] = 126;
            }
          if (counting == 40 && intervalChange)
           {
            setRed();
            red[7] = 128;
            }
          if (counting == 41 && intervalChange)
           {
            setRed();
            red[7] = 128;
            }
          if (counting == 42 && intervalChange)
           {
            setRed();
            red[7] = 126;
            }
          if (counting == 43 && intervalChange)
           {
            setRed();
            red[7] = 0;
            }
          if (counting == 44 && intervalChange)
           {
            setRed();
            red[7] = 254;
            }
          if (counting == 45 && intervalChange)
           {
            setRed();
            red[7] = 18;
            }
          if (counting == 46 && intervalChange)
           {
            setRed();
            red[7] = 50;
            }
          if (counting == 47 && intervalChange)
           {
            setRed();
            red[7] = 82;
            }
          if (counting == 48 && intervalChange)
           {
            setRed();
            red[7] = 140;
            }
          if (counting == 49 && intervalChange)
           {
            setRed();
            red[7] = 0;
            }
          if (counting == 50 && intervalChange)
           {
            setRed();
            red[7] = 158;
            counting = 0;
            }
         elapsedmillisloop();
  } 
}
    void setRed () 
      {
            intervalChange = false;
            red[0] = red[1];
            red[1] = red[2];
            red[2] = red[3];
            red[3] = red[4];
            red[4] = red[5];
            red[5] = red[6];
            red[6] = red[7];
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
