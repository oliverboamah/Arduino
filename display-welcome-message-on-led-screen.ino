#include "LedControl.h"; // useful library for led control

LedControl LedControl = LedControl(12, 10, 11);  // Pins: DIN, CLK, CS

unsigned long delayTime = 2000;  // delay time btn letter frames in miliseconds

/**
 *
 * Letter Frames Array
 *
*/

byte frameW[] =
{
   B10000001,  
   B10000001,
   B10000001,
   B10000001,
   B10000001,
   B10011001,
   B10100101,
   B10000001,
};

byte frameE[] =
{
   B11111111,
   B10000000,
   B10000000,
   B10000000,
   B11111100,
   B10000000,
   B10000000,
   B11111111,
};

byte frameL[] =
{
   B10000000,
   B10000000,
   B10000000,
   B10000000,
   B10000000,
   B10000000,
   B10000000,
   B11111111,
};

byte frameC[] =
{
   B01111111,  
   B10000000,
   B10000000,
   B10000000,
   B10000000,
   B10000000,
   B10000000,
   B01111111,
};

byte frameO[] =
{
   B01111110, 
   B10000001,
   B10000001,
   B10000001,
   B10000001,
   B10000001,
   B10000001,
   B01111110,
};

byte frameM[] =
{
   B10000001,  
   B10100101,
   B10011001,
   B10000001,
   B10000001,
   B10000001,
   B10000001,
   B10000001,
};

void setup()
{
  // wake up displays on both screens
  lc.shutdown(0,false);  
  lc.shutdown(1,false);

  // set intensity levels on both screens
  lc.setIntensity(0,5);  
  lc.setIntensity(1,5);

  // clear displays on both screens
  lc.clearDisplay(0);  
  lc.clearDisplay(1);
}

void loop()
{
    displayFrame(frameW);
    delay(delayTime);

    displayFrame(frameE);
    delay(delayTime);

    displayFrame(frameL);
    delay(delayTime);

    displayFrame(frameC);
    delay(delayTime);

    displayFrame(frameO);
    delay(delayTime);

    displayFrame(frameM);
    delay(delayTime);

    displayFrame(frameE);
    delay(delayTime);
};

void displayFrame(byte frame[])
{
  for (int i = 0; i < 8; i++)  
  {
    lc.setRow(0, i, frame[i]);
  }
}