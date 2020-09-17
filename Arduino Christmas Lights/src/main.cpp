
#include <Arduino.h>
#include <Adafruit_NeoPixel.h>
#define LED_PIN     5
int numLEDs;
byte ledInpuSwitches;
void flashGreenRed(void);
void (*effects[5])();
Adafruit_NeoPixel strip;

void setup() {

  //setup inut output pins as input or output  Yes the numbers are weird, It;s because of the weird forfactor of the ESP32 Dekit-1 That I chose
  //The numbers are out of order here so they line up nice in the circuit design, makes my life easier.
  pinMode(LED_PIN,OUTPUT);
  pinMode(6,INPUT);
  pinMode(7,INPUT);
  pinMode(8,INPUT);
  pinMode(15,INPUT);
  pinMode(2,INPUT);
  pinMode(0,INPUT);
  pinMode(4,INPUT);
  pinMode(16,INPUT);
  pinMode(17,INPUT);
  pinMode(18,INPUT);
  pinMode(5,OUTPUT);

  //Taking inthe switch values and detemining the umber of LEDs present in the Light.  Thanks to Brendon Gluth(https://github.com/BGluth) for help with the boolean logic in this part of the code.
  ledInpuSwitches |= digitalRead(6) << 0;
  ledInpuSwitches |= digitalRead(7) << 1;
  ledInpuSwitches |= digitalRead(8) << 2;
  ledInpuSwitches |= digitalRead(15) << 3;
  ledInpuSwitches |= digitalRead(2) << 4; 
  ledInpuSwitches |= digitalRead(0) << 5;
  ledInpuSwitches |= digitalRead(4) << 6;
  ledInpuSwitches |= digitalRead(16) << 7;

  //Taking the base number and doubling it if necessary
  numLEDs = (int)ledInpuSwitches * (digitalRead(17) + 1);
  strip = Adafruit_NeoPixel(numLEDs, LED_PIN, NEO_GRB + NEO_KHZ800);
  //Setup Pointer array for effects functions
  effects[0] = flashGreenRed;
  effects[1] = flashBlueRed;
  effects[2] = flashBlueGreen;
  effects[3] = flashRed;
  effects[4] = flashGreen;
  effects[5] = flashBlue;
  effects[7] = flashPink;
  

}

void loop() 
{
    
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
void flashRed()
{
  for(int i = 0; i< numLEDs; i ++)
  {
    strip.setPixelColor(i,255,0,0);
  }
  delay(1000);
  for(int i = 0; i< numLEDs; i ++)
  {
    strip.setPixelColor(i,0,0,0);
  }
  delay(1000);
}
void flashGreen()
{
  for(int i = 0; i< numLEDs; i ++)
  {
    strip.setPixelColor(i,0,255,0);
  }
  delay(1000);
  for(int i = 0; i< numLEDs; i ++)
  {
    strip.setPixelColor(i,0,0,0);
  }
  delay(1000);
}
void flashBlue()
{
  for(int i = 0; i< numLEDs; i ++)
  {
    strip.setPixelColor(i,0,0,255);
  }
  delay(1000);
  for(int i = 0; i< numLEDs; i ++)
  {
    strip.setPixelColor(i,0,0,0);
  }
  delay(1000);
}
void flashPink()
{
  for(int i = 0; i< numLEDs; i ++)
  {
    strip.setPixelColor(i,216,0,255);
  }
  delay(1000);
  for(int i = 0; i< numLEDs; i ++)
  {
    strip.setPixelColor(i,0,0,0);
  }
  delay(1000);
}