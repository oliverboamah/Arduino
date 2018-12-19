int PIN_LED = 9;
int brightnessValue = 0;
int fadingValue = 5;
unsigned long delayTime = 2000;

void setup()
{
  pinMode(PIN_LED, OUTPUT);
}

void loop() 
{
  analogWrite(PIN_LED, brightnessValue);
  brightnessValue = brightnessValue + fadingValue;

  delay(delayTime);

  if(bright > 200)
  {
    fading = -5;
  } 
  else if( bright < 0)
  {
    fading = 5;
  }
}