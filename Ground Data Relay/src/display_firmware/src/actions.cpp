#include "actions.h"
#include "sensors.h"

bool ACTIONS::checkIfStandby(uint8_t speed, uint8_t ultrasonicValue) {
  // Add your implementation to check if the system is in standby mode
  // based on the speed and ultrasonic sensor value
  // Return true if in standby mode, false otherwise
  // Example implementation:
  return (speed == 0 && ultrasonicValue == 0);
}

bool ACTIONS::onModeCharge(uint8_t speed) {
  // Add your implementation to check if the system is in charge mode
  // based on the speed
  // Return true if in charge mode, false otherwise
  // Example implementation:
  return (speed > 0 && speed < 10);
}

bool ACTIONS::onModeCoast(uint8_t speed) {
  // Add your implementation to check if the system is in coast mode
  // based on the speed
  // Return true if in coast mode, false otherwise
  // Example implementation:
  return (speed >= 10 && speed < 20);
}

bool ACTIONS::onModePush(uint8_t speed) {
  // Add your implementation to check if the system is in push mode
  // based on the speed
  // Return true if in push mode, false otherwise
  // Example implementation:
  return (speed >= 20);
}

String ACTIONS::detectPlacement(uint8_t ultrasonicValue) {
  // Add your implementation to detect the placement based on the ultrasonic sensor value
  // Return a string indicating the placement
  // Example implementation:
  if (ultrasonicValue > 0 && ultrasonicValue < 50) {
    return "Front";
  } else if (ultrasonicValue >= 50 && ultrasonicValue < 100) {
    return "Middle";
  } else {
    return "Back";
  }
}