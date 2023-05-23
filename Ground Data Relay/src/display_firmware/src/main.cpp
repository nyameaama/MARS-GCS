#include <Arduino.h>
#include "DisplayInterface.h"

DisplayInterface display;

void setup() { 
  display.begin();
}

void loop() {
  display.reset();
  display.updateDroneStates();
  delay(1000);
}