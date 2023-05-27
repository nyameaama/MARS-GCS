#include <Arduino.h>
#include "DisplayInterface.h"

DisplayInterface display;

void setup() {
  Serial.begin(9600); 
  display.begin();
}

void loop() {
  display.reset();
  display.state();
  //display.displayInnerMenuMotorFL();
  delay(1000);
}