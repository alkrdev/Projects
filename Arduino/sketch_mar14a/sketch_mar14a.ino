int DATA               = 3;
int DATA_OUTPUT_ENABLE = 4;
int LATCH              = 5;
int CLOCK              = 6;
int RESET              = 7;

byte Screen[8][8] = {{0,0,0,0,0,0,0,0},
                     {0,0,0,0,0,0,0,0},
                     {0,0,0,0,0,0,0,0},
                     {0,0,0,0,0,0,0,0},
                     {0,0,0,0,0,0,0,0},
                     {0,0,0,0,0,0,0,0},
                     {0,0,0,0,0,0,0,0},
                     {0,0,0,0,0,0,0,0}};

byte Test3[8][8] =   {{2,2,2,2,2,2,2,2},
                      {2,2,2,2,2,2,2,2},
                      {2,2,2,2,2,2,2,2},
                      {2,2,2,2,2,2,2,2},
                      {2,2,2,2,2,2,2,2},
                      {2,2,2,2,2,2,2,2},
                      {2,2,2,2,2,2,2,2},
                      {2,2,2,2,2,2,2,2}}; 

byte Test2[8][8] =   {{1,1,1,1,1,1,1,1},
                      {1,1,1,1,1,1,1,1},
                      {1,1,1,1,1,1,1,1},
                      {1,1,1,1,1,1,1,1},
                      {1,1,1,1,1,1,1,1},
                      {1,1,1,1,1,1,1,1},
                      {1,1,1,1,1,1,1,1},
                      {1,1,1,1,1,1,1,1}};

byte Test1[8][8] =   {{4,4,4,4,4,4,4,4},
                      {4,4,4,4,4,4,4,4},
                      {4,4,4,4,4,4,4,4},
                      {4,4,4,4,4,4,4,4},
                      {4,4,4,4,4,4,4,4},
                      {4,4,4,4,4,4,4,4},
                      {4,4,4,4,4,4,4,4},
                      {4,4,4,4,4,4,4,4}};

unsigned long LastStateChangeTime;
unsigned long StateWaitTime;
int State;

void sendBit(uint8_t aData)
{
  digitalWrite(DATA,  aData);  
  digitalWrite(CLOCK, HIGH);
  digitalWrite(CLOCK, LOW);
  digitalWrite(DATA,  LOW);  
}

void sendDataFromArray()
{
  byte lineIndex;
  byte rowIndex;

  for(lineIndex = 0; lineIndex < 8; lineIndex++)
  {
    //Set Anode Line
    for(rowIndex = 0; rowIndex < 8; rowIndex++)
    {
      if (lineIndex == rowIndex)
      {
        sendBit(HIGH);
      }
      else
      {
        sendBit(LOW);
      }
    }

    //Set Green Row
    for(rowIndex = 0; rowIndex < 8; rowIndex++)
    {
      if ((Screen[lineIndex][rowIndex] & 1) == 0)
      {
        sendBit(HIGH);
      }
      else
      {
        sendBit(LOW);
      }
    }

    //Set Red Row
    for(rowIndex = 0; rowIndex < 8; rowIndex++)
    {
      if ((Screen[lineIndex][rowIndex] & 2) == 0)
      {
        sendBit(HIGH);
      }
      else
      {
        sendBit(LOW);
      }
    }

    //Set Blue Row
    for(rowIndex = 0; rowIndex < 8; rowIndex++)
    {
      if ((Screen[lineIndex][rowIndex] & 4) == 0)
      {
        sendBit(HIGH);
      }
      else
      {
        sendBit(LOW);
      }
    }

    //Send data to output
    digitalWrite(LATCH, HIGH);
    digitalWrite(LATCH, LOW);
  }
}

void Clear()
{  
  byte lineIndex;
  byte rowIndex;

  for(lineIndex = 0; lineIndex < 8; lineIndex++)
  {
    for(rowIndex = 0; rowIndex < 8; rowIndex++)
    {
      Screen[lineIndex][rowIndex] = 0;
    }
  }
}


void ShowTest1()
{  
  byte lineIndex;
  byte rowIndex;

  for(lineIndex = 0; lineIndex < 8; lineIndex++)
  {
    for(rowIndex = 0; rowIndex < 8; rowIndex++)
    {
      Screen[lineIndex][rowIndex] = Test1[lineIndex][rowIndex];
    }
  }
}
void ShowTest2()
{  
  byte lineIndex;
  byte rowIndex;

  for(lineIndex = 0; lineIndex < 8; lineIndex++)
  {
    for(rowIndex = 0; rowIndex < 8; rowIndex++)
    {
      Screen[lineIndex][rowIndex] = Test2[lineIndex][rowIndex];
    }
  }
}
void ShowTest3()
{  
  byte lineIndex;
  byte rowIndex;

  for(lineIndex = 0; lineIndex < 8; lineIndex++)
  {
    for(rowIndex = 0; rowIndex < 8; rowIndex++)
    {
      Screen[lineIndex][rowIndex] = Test3[lineIndex][rowIndex];
    }
  }
}

void ShowRainBow()
{  
  byte lineIndex;
  byte rowIndex;

  for(lineIndex = 0; lineIndex < 8; lineIndex++)
  {
    Screen[lineIndex][0] = 0;
    Screen[lineIndex][1] = 1;
    Screen[lineIndex][2] = 2;
    Screen[lineIndex][3] = 3;
    Screen[lineIndex][4] = 4;
    Screen[lineIndex][5] = 5;
    Screen[lineIndex][6] = 6;
    Screen[lineIndex][7] = 7;
  }
}

void ScrollUp(byte NewLine[])
{
  byte lineIndex;
  byte rowIndex;

  for(lineIndex = 0; lineIndex < 7; lineIndex++)
  {
    for(rowIndex = 0; rowIndex < 8; rowIndex++)
    {
      Screen[lineIndex][rowIndex] = Screen[lineIndex+1][rowIndex];
    }
  }

  for(rowIndex = 0; rowIndex < 8; rowIndex++)
  {
    Screen[7][rowIndex] = NewLine[rowIndex];
  }
}

void UpdateState()
{
  State++;
  if (State == 19)
  {
    State = 0;
  }

  LastStateChangeTime = millis();
  switch (State)
  {
    case 0:
      ShowTest1();
      StateWaitTime = 400;
      break; 
    case 1:
      ShowTest2();
      StateWaitTime = 400;
      break; 
    case 2:
      ShowTest3();
      StateWaitTime = 400;
      break; 
    case 3:
      ShowTest1();
      StateWaitTime = 400;
      break; 
    case 4:
      ShowTest2();
      StateWaitTime = 400;
      break; 
    case 5:
      ShowTest3();
      StateWaitTime = 400;
      break;  
    case 6:
      ShowTest1();
      StateWaitTime = 400;
      break; 
    case 7:
      ShowTest2();
      StateWaitTime = 400;
      break; 
    case 8:
      ShowTest3();
      StateWaitTime = 400;
      break; 
    case 9:
      ShowTest1();
      StateWaitTime = 400;
      break; 
    case 10:
      ShowTest2();
      StateWaitTime = 400;
      break; 
    case 11:
      ShowTest3();
      StateWaitTime = 400;
      break; 
    case 12:
      ShowTest1();
      StateWaitTime = 400;
      break; 
    case 13:
      ShowTest2();
      StateWaitTime = 400;
      break;    
    case 14:
      ShowTest3();
      StateWaitTime = 400;
      break; 
    case 15:
      ShowTest1();
      StateWaitTime = 400;
      break; 
    case 16:
      ShowTest2();
      StateWaitTime = 400;
      break; 
    case 17:
      ShowTest3();
      StateWaitTime = 400;
      break; 
    case 18:
      ShowTest1();
      StateWaitTime = 400;
      break; 
    case 19:
      ShowTest2();
      StateWaitTime = 400;
      break; 
    case 20:
      ShowTest3();
      StateWaitTime = 400;
      break; 
  }
}

void setup() 
{
  pinMode(DATA, OUTPUT);
  pinMode(DATA_OUTPUT_ENABLE, OUTPUT);
  pinMode(LATCH, OUTPUT);
  pinMode(CLOCK, OUTPUT);
  pinMode(RESET, OUTPUT);

  digitalWrite(DATA_OUTPUT_ENABLE, LOW);
  digitalWrite(RESET, HIGH); 
  digitalWrite(CLOCK, LOW);
  digitalWrite(LATCH, LOW);
  digitalWrite(DATA, LOW);
  
  ShowRainBow();
  State = 0;
  StateWaitTime = 2000;
  LastStateChangeTime = millis();
}

void loop() 
{
  if ((StateWaitTime > 0) &&
      (LastStateChangeTime + StateWaitTime < millis()))
  {
    UpdateState();
  }  
  
  sendDataFromArray();
}
