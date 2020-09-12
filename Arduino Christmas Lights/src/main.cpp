
#include <Arduino.h>
#include <Adafruit_NeoPixel.h>
#define LED_PIN     5
int numLEDs;
byte ledInpuSwitches;
void flashGreenRed(void);
void (*effects[5])();
Adafruit_NeoPixel strip;

void setup() {

  //setup inut output pins as input or output

  pinMode(LED_PIN,OUTPUT);
  pinMode(22,INPUT);
  pinMode(23,INPUT);
  pinMode(24,INPUT);
  pinMode(25,INPUT);
  pinMode(26,INPUT);
  pinMode(27,INPUT);
  pinMode(28,INPUT);
  pinMode(29,INPUT);
  pinMode(30,INPUT);

  //Taking inthe switch values and detemining the umber of LEDs present in the Light.  Thanks to Brendon Gluth(https://github.com/BGluth) for help with the boolean logic in this part of the code.
  ledInpuSwitches |= digitalRead(22) << 0;
  ledInpuSwitches |= digitalRead(23) << 1;
  ledInpuSwitches |= digitalRead(24) << 2;
  ledInpuSwitches |= digitalRead(25) << 3;
  ledInpuSwitches |= digitalRead(26) << 4; 
  ledInpuSwitches |= digitalRead(27) << 5;
  ledInpuSwitches |= digitalRead(28) << 6;
  ledInpuSwitches |= digitalRead(29) << 7;

  //Taking the base number and doubling it if necessary
  numLEDs = (int)ledInpuSwitches * (digitalRead(30) + 1);
  strip = Adafruit_NeoPixel(numLEDs, LED_PIN, NEO_GRB + NEO_KHZ800);
  //Setup Pointer array for effects functions
  effects[0] = flashGreenRed;
  effects[1] = flashBlueRed;
  effects[2] = flashBlueGreen;
  

}

void loop() {


  // put your main code here, to run repeatedly:
}


void flashGreenRed()
{
  for(int i = 0; i< numLEDs; i += 2)
  {
    strip.setPixelColor(i,255,0,0);
  }
  delay(1000);
  for(int i = 0; i< numLEDs; i += 2)
  {
    strip.setPixelColor(i,0,255,0);
  }
  delay(1000);
}
void flashBlueRed()
{
  for(int i = 0; i< numLEDs; i ++)
  {
    strip.setPixelColor(i,255,0,0);
  }
  delay(1000);
  for(int i = 0; i< numLEDs; i ++)
  {
    strip.setPixelColor(i,0,0,255);
  }
  delay(1000);
}
void flashBlueGreen()
{
  for(int i = 0; i< numLEDs; i ++)
  {
    strip.setPixelColor(i,0,0,255);
  }
  delay(1000);
  for(int i = 0; i< numLEDs; i ++)
  {
    strip.setPixelColor(i,0,255,0);
  }
  delay(1000);
}