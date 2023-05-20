#ifndef ACTIONS_H
#define ACTIONS_H

#include <Arduino.h>

class ACTIONS {
public:
  bool checkIfStandby(uint8_t speed, uint8_t ultrasonicValue);
  bool onModeCharge(uint8_t speed);
  bool onModeCoast(uint8_t speed);
  bool onModePush(uint8_t speed);
  String detectPlacement(uint8_t ultrasonicValue);
};

#endif