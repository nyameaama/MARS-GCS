#include "DisplayInterface.h"

#define LCD_CS A3
#define LCD_CD A2
#define LCD_WR A1
#define LCD_RD A0
#define LCD_RESET A4

#define LCD_WIDTH 320
#define LCD_HEIGHT 480

#define ARROWB_X 30
#define ARROWB_Y 190

#define ARROW_X 80
#define ARROW_Y 120
#define ARROW_SIZE 10

const uint16_t BLACK       = 0x0000;
const uint16_t WHITE       = 0xFFFF;

DisplayInterface::DisplayInterface() : tft(LCD_CS, LCD_CD, LCD_WR, LCD_RD, LCD_RESET) {}

void DisplayInterface::begin() {
  tft.begin(0x9486);
  tft.setRotation(1);
  tft.fillScreen(0x0000);
}

void DisplayInterface::updateDroneStates() {
  displayDroneState();
  displayTime();
  displayVelocity();
  displayGPS();
  displayMotorPositions();
  displayPitchRollYaw();
  displayTitle();
  displayPlatform();
  displayConnectionState();
  UplinkDownlink();
}

void DisplayInterface::displayDroneState() {
  tft.setTextColor(0xFFFF);
  tft.setTextSize(7);
  tft.setCursor(120, 140);
  tft.println("ACTIVE");
  tft.drawRect(110, 115, 270, 100,WHITE);
  // Add your code to update the drone state
}

void DisplayInterface::displayConnectionState() {
  tft.setTextColor(0xFFFF);
  tft.setTextSize(2);
  tft.setCursor(200, 40);
  tft.println("CONNECTION: ESTABLISHED");
  // Add your code to update the time
  
}
void DisplayInterface::displayTime() {
  tft.setTextColor(0xFFFF);
  tft.setTextSize(2);
  tft.setCursor(10, 40);
  tft.println("Time:");
  // Add your code to update the time
}


void DisplayInterface::UplinkDownlink() {
  tft.setTextColor(0xFFFF);
  tft.setTextSize(2);
  tft.setCursor(10, 80);
  tft.println("Uplink/Downlink");
  // Draw the arrow pointing up
  tft.setCursor(75, 130);
  tft.println("|");
  tft.setCursor(75, 150);
  tft.println("|");
  tft.setCursor(75, 170);
  tft.println("|");
  tft.setCursor(75, 150);
  tft.println("|");
  tft.setCursor(25, 150);
  tft.println("|");
  tft.setCursor(25, 170);
  tft.println("|");
  tft.setCursor(25, 130);
  tft.println("|");
  tft.setCursor(75, 150);
  tft.println("|");
  
  // Draw the arrow pointing up
  tft.fillTriangle(ARROW_X, ARROW_Y - ARROW_SIZE, ARROW_X - ARROW_SIZE, ARROW_Y, ARROW_X + ARROW_SIZE, ARROW_Y,  0xFFFF);
  // Draw the arrow pointing down
  tft.fillTriangle(ARROWB_X, ARROWB_Y + ARROW_SIZE, ARROWB_X - ARROW_SIZE, ARROWB_Y, ARROWB_X + ARROW_SIZE, ARROWB_Y, 0xFFFF);
  // Add your code to update the time
   //tft.drawRect(110, 115, 270, 100,WHITE);
}

void DisplayInterface::displayTitle() {
  tft.setTextColor(0xFFFF);
  tft.setTextSize(2);
  tft.setCursor(10, 10);
  tft.println("LIMITLESS AERONAUTICS -->");
  // Add your code to update the time
}

void DisplayInterface::displayPlatform() {
  tft.setTextColor(0xFFFF);
  tft.setTextSize(2);
  tft.setCursor(220, 90);
  tft.println("HIVE");
  // Add your code to update the time
}

void DisplayInterface::displayVelocity() {
  tft.setTextColor(0xFFFF);
  tft.setTextSize(2);
  tft.setCursor(330, 290);
  tft.println("Velocity:");
  // Add your code to update the velocity
}

void DisplayInterface::displayGPS() {
  tft.setTextColor(0xFFFF);
  tft.setTextSize(2);
  tft.setCursor(330, 230);
  tft.println("Latitude:"+ String(90));
  tft.setCursor(330, 250);
  tft.println("Longitude:"+ String(90));
  tft.setCursor(330, 270);
  tft.println("Altitude:"+ String(90));
  // Add your code to update the GPS latitude and longitude
}

void DisplayInterface::displayMotorPositions() {
  tft.setTextColor(0xFFFF);
  tft.setTextSize(2);

   tft.setCursor(10, 230);
   tft.println("Motor 1:"+ String(90));

   tft.setCursor(10, 250);
   tft.println("Motor 2:" + String(90));

   tft.setCursor(10, 270);
   tft.println("Motor 3:" + String(90));

   tft.setCursor(10, 290);
   tft.println("Motor 4:" + String(90));
   
}

void DisplayInterface::displayPitchRollYaw() {
  tft.setTextColor(0xFFFF);
  tft.setTextSize(2);
  tft.setCursor(180, 230);
  tft.println("Pitch:"+ String(90));
  tft.setCursor(180, 250);
  tft.println("Roll:"+ String(90));
  tft.setCursor(180, 270);
  tft.println("Yaw:"+ String(90));
  // Add your code to update the pitch, roll, and yaw
}

String DisplayInterface::formatMotorPosition(int position) {
  String formattedPosition = String(position);
  while (formattedPosition.length() < 3) {
    formattedPosition = " " + formattedPosition;
  }
  return formattedPosition;
}