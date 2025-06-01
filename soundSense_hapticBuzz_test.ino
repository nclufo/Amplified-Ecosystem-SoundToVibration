#include <Wire.h>
#include "Adafruit_DRV2605.h"

Adafruit_DRV2605 drv;
int soundSen = A0;
int soundVal = 0;
int soundMap = 0;

void setup() {
  Serial.begin(9600);

  pinMode(soundSen, INPUT);
  
  drv.begin();

  drv.setMode(DRV2605_MODE_INTTRIG); 

  drv.selectLibrary(1);
  drv.setWaveform(0, 14); 
  drv.setWaveform(1, 0);  

}

void loop() {
  drv.go();

  readSound();

  soundMap = map(soundVal, 0, 500, 10, 1900);
  Serial.println(soundMap);

  delay(2000 - soundMap);
}

void readSound(){
  for (int i = 0; i < 32; i++) { 
    soundVal += analogRead(soundSen);  
    }
  soundVal >>= 1; 
  if (soundVal >= 500){
    soundVal = 499;
    }
  delay(50);

// soundVal = analogRead(soundSen);
// Serial.println(soundVal);
// delay(50);
}