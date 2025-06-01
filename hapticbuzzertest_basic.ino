#include <Wire.h>
#include "Adafruit_DRV2605.h"

Adafruit_DRV2605 drv;

void setup() {
  Serial.begin(9600);
  Serial.println("DRV test");
  drv.begin();
    
 
  drv.setMode(DRV2605_MODE_INTTRIG); 

  drv.selectLibrary(1);
  drv.setWaveform(0, 1);
  drv.setWaveform(1, 24);
  drv.setWaveform(2, 37);
  drv.setWaveform(3, 74);  
  drv.setWaveform(4, 0);  
}

void loop() {
    drv.go();
    delay(2000);
}