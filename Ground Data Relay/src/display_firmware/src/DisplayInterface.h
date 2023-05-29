#ifndef DISPLAY_INTERFACE_H
#define DISPLAY_INTERFACE_H

#include <MCUFRIEND_kbv.h>
#include <Adafruit_GFX.h>
#include"Sensors.h"

class DisplayInterface {
  public:
    DisplayInterface();
    int state(uint8_t PAGE);
    void reset();
    void begin();
    bool isTouchInArea(int touchX, int touchY,int areaX,int areaY,int areaWidth,int areaHeight);
    void readResistiveTouch(void);
    bool ISPRESSED(void);
    void updateDroneStates();
    void updateBypassPage();
    void displayInnerMenuMotorFL();
    void displayInnerMenuMotorFR();
    void displayInnerMenuMotorRR();
    void displayInnerMenuMotorRL();
    void displayInnerMenuThrottle();
    void displayMenuBackL1();
  
  private:
    MCUFRIEND_kbv tft;

    void displayDroneState();
    void displayMenuButton(int color,int colorBg);
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

    void displayMenuMotorFL();
    void displayMenuMotorFR();
    void displayMenuMotorRR();
    void displayMenuMotorRL();
    void displayMenuThrottle();

};

#endif // DISPLAY_INTERFACE_H