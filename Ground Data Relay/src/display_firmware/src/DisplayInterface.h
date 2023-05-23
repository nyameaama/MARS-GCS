#ifndef DISPLAY_INTERFACE_H
#define DISPLAY_INTERFACE_H

#include <MCUFRIEND_kbv.h>
#include <Adafruit_GFX.h>
#include"Sensors.h"

class DisplayInterface {
  public:
    DisplayInterface();
    void reset();
    void begin();
    void updateDroneStates();
    
  private:
    MCUFRIEND_kbv tft;

    void displayDroneState();
    void displayMenuButton();
    void displayTime();
    void displayVelocity();
    void displayGPS();
    void displayMotorPositions();
    void displayPitchRollYaw();
    void displayTitle();
    void displayPlatform();
    void displayConnectionState();
    void UplinkDownlink();
    String formatMotorPosition(int position);
};
