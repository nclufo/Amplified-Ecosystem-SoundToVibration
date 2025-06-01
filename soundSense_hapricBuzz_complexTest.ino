#include <Wire.h>
#include "Adafruit_DRV2605.h"

Adafruit_DRV2605 drv;
int soundSen = A0;
int soundVal = 0;
int soundMap = 0;

void setup() {
  Serial.begin(9600);
 
  pinMode(soundSen, INPUT);

  drv.selectLibrary(1);

  drv.setMode(DRV2605_MODE_INTTRIG); 
}

uint8_t effect = 1;

void loop() {


  drv.setWaveform(0, effect);
  drv.setWaveform(1, 0);

  drv.go();

  readSound();

  soundMap = map(soundVal, 0, 500, 10, 500);
  Serial.println(soundMap);

  delay(505 - soundMap);

  effect++;
if (effect > 3) effect = 1;
}

void readSound(){
  for (int i = 0; i < 32; i++) { 
    soundVal += analogRead(soundSen);  
    }
  soundVal >>= 1; 
  if (soundVal >= 500){
    soundVal = 499;
    }
  delay(50);}
