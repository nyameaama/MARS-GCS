#ifndef SENSORS_H
#define SENSORS_H

#include <Arduino.h>

class Sensors {
public:
  void begin(unsigned long baudRate);
  String requestData(const String& request);
  uint8_t speed();
  float checkGPS();
  float checkUltrasonics();
  int32_t altitude();
  long int latitude();
  long int longitude();
  uint32_t satellites();
  uint32_t time();
  uint32_t date();
  float pitch();
  float roll();
  float yaw();
  uint8_t ultrasonic_sensors(uint8_t sensorIndex, uint8_t dummyValue);
};

#endif