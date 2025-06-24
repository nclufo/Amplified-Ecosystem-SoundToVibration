#include <Wire.h>
#include "Adafruit_DRV2605.h"

Adafruit_DRV2605 drv;
const int micPin = A0;
int readMic;
int micMap;

void setup() {
  Serial.begin(9600);

  pinMode(micPin, INPUT);

  drv.begin();
  drv.setMode(DRV2605_MODE_INTTRIG); 
  drv.selectLibrary(1);
  drv.setWaveform(0, 1);
  drv.setWaveform(1, 14); 
  drv.setWaveform(2, 7);
  drv.setWaveform(3, 0);  
}

void loop() {
  readSound();

  micMap = map(readMic, 0, 20, 0, 800);
  Serial.println(micMap);

  playBuzz();
}

void readSound(){
  // read input from contact mic
  readMic = analogRead(micPin);
  //Serial.print(readMic+",");
  delay(50);
}

void playBuzz(){
  drv.go();
  if (micMap >1500){
    micMap = 0;
  }
  delay(2000 - micMap);
}