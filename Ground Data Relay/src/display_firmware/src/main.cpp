#include <Arduino.h>
#include "DisplayInterface.h"

uint8_t PAGE = 1;

DisplayInterface display;

void setup() {
  Serial.begin(9600); 
  display.begin();
}

void loop() {
  display.reset();
  int newState = display.state(PAGE);
  PAGE = newState;
  delay(1000);
}