#include "DisplayInterface.h"
#define PAGE 1

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
// MCUFRIEND UNO shield shares pins with the TFT.
#if defined(ESP32)
int XP = 27, YP = 4, XM = 15, YM = 14;  //most common configuration
#else
//int XP = 6, YP = A1, XM = A2, YM = 7;  //most common configuration
int XP = 7, YP = A2, XM = A1, YM = 6;  //next common configuration
//int XP=PB7,XM=PA6,YP=PA7,YM=PB6; //BLUEPILL must have Analog for YP, XM
#endif
#if USE_LOCAL_KBV
#include "TouchScreen_kbv.h"         //my hacked version
#define TouchScreen TouchScreen_kbv
#define TSPoint     TSPoint_kbv
#else
#include <TouchScreen.h>         //Adafruit Library
#endif
TouchScreen ts(XP, YP, XM, YM, 300);   //re-initialised after diagnose
TSPoint tp;                            //global point


DisplayInterface::DisplayInterface() : tft(LCD_CS, LCD_CD, LCD_WR, LCD_RD, LCD_RESET) {}

void DisplayInterface::readResistiveTouch(void){
    tp = ts.getPoint();
    pinMode(YP, OUTPUT);      //restore shared pins
    pinMode(XM, OUTPUT);
    //digitalWrite(YP, HIGH);  //because TFT control pins
    //digitalWrite(XM, HIGH);
    //    Serial.println("tp.x=" + String(tp.x) + ", tp.y=" + String(tp.y) + ", tp.z =" + String(tp.z));
}

bool DisplayInterface::isTouchInArea(int touchX, int touchY,int areaX,int areaY,int areaWidth,int areaHeight) {
  if (touchX >= areaX && touchX <= areaX + areaWidth &&
      touchY >= areaY && touchY <= areaY + areaHeight) {
    return true;
  }
  return false;
}

bool DisplayInterface::ISPRESSED(void)
{
    // .kbv this was too sensitive !!
    // now touch has to be stable for 50ms
    int count = 0;
    bool state, oldstate;
    while (count < 10) {
        readResistiveTouch();
        state = tp.z > 200;     //ADJUST THIS VALUE TO SUIT YOUR SCREEN e.g. 20 ... 250
        if (state == oldstate) count++;
        else count = 0;
        oldstate = state;
        delay(5);
    }
    return oldstate;
}


void DisplayInterface::begin() {
  tft.begin(0x9486);
  tft.setRotation(1);
  tft.fillScreen(0x0000);
}

void DisplayInterface::reset(){
    tft.fillScreen(0x0000);
}

void DisplayInterface::state(){
  //updateDroneStates();
  //updateBypassPage();
  displayInnerMenuMotorFL();
  // Read the touch coordinates
  if(ISPRESSED() == true){
    Serial.println("Pressed");
  }else{
    //Serial.println("No Press");
  }
  Serial.print("tp.x=");
Serial.print(tp.x);
Serial.print(", tp.y=");
Serial.print(tp.y);
Serial.print(", tp.z=");
Serial.println(tp.z);
    readResistiveTouch();
    // Check if the touch point is within the specified area
    if (isTouchInArea(tp.x, tp.y,390, 125, 90, 50)) {
      Serial.println("Pressed");
      // Touch is detected in the specific area
      // Perform the desired actions
      // ...
      #undef PAGE
      #define PAGE 2
      updateBypassPage();
    }

}

void DisplayInterface::updateDroneStates() {
  displayDroneState();
  displayPlatform();
  displayConnectionState();
  displayTitle();
  displayTime();
  UplinkDownlink();
  displayVelocity();
  displayMotorPositions();
  displayGPS();
  displayPitchRollYaw();
  displayMenuButton();
}

void DisplayInterface::updateBypassPage(){
   displayMenuMotorFL();
   displayMenuMotorFR();
   displayMenuMotorRR();
   displayMenuMotorRL();
   displayMenuThrottle();
}

void DisplayInterface::displayDroneState() {
  tft.setTextColor(0xFFFF);
  tft.setTextSize(7);
  tft.setCursor(120, 140);
  tft.println("ACTIVE");
  tft.drawRect(110, 115, 270, 100,WHITE);
  // Add your code to update the drone state
}

void DisplayInterface::displayMenuButton(){
  tft.setTextColor(0xFFFF);
  tft.setTextSize(3);
  tft.setCursor(400, 140);
  tft.println("Menu");
  tft.drawRect(390, 125, 90, 50,WHITE);
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
  tft.setCursor(300, 290);
  tft.println("Velocity:");
  // Add your code to update the velocity
}

void DisplayInterface::displayGPS() {
  tft.setTextColor(0xFFFF);
  tft.setTextSize(2);
  tft.setCursor(300, 230);
  Sensors *obj = new Sensors();
  float val = obj -> latitude();
  float val2 = obj -> longitude();
  float val3 = obj -> altitude();
  tft.println("Latitude:"+ String(val));
  tft.setCursor(300, 250);
  tft.println("Longitude:"+ String(val2));
  tft.setCursor(300, 270);
  tft.println("Altitude:"+ String(val3));
  delete obj;
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
  tft.setCursor(150, 230);
  Sensors *obj = new Sensors();
  float val1 = obj -> pitch();
  float val2 = obj -> roll();
  float val3 = obj -> yaw();
  tft.println("Pitch:"+ String(val1));
  tft.setCursor(150, 250);
  tft.println("Roll:"+ String(val2));
  tft.setCursor(150, 270);
  tft.println("Yaw:"+ String(val3));
  delete obj;
}

String DisplayInterface::formatMotorPosition(int position) {
  String formattedPosition = String(position);
  while (formattedPosition.length() < 3) {
    formattedPosition = " " + formattedPosition;
  }
  return formattedPosition;
}

void DisplayInterface::displayMenuMotorFL() {
  tft.setTextColor(0xFFFF);
  tft.setTextSize(3);
  tft.setCursor(30, 25);
  tft.println("Set Motor FL          ->");
  tft.drawRect(10, 10, 460, 50,WHITE);
}

void DisplayInterface::displayMenuMotorFR() {
  tft.setTextColor(0xFFFF);
  tft.setTextSize(3);
  tft.setCursor(30, 85);
  tft.println("Set Motor FR          ->");
  tft.drawRect(10, 70, 460, 50,WHITE);
}

void DisplayInterface::displayMenuMotorRL() {
  tft.setTextColor(0xFFFF);
  tft.setTextSize(3);
  tft.setCursor(30, 145);
  tft.println("Set Motor RL          ->");
  tft.drawRect(10, 130, 460, 50,WHITE);
}

void DisplayInterface::displayMenuMotorRR() {
  tft.setTextColor(0xFFFF);
  tft.setTextSize(3);
  tft.setCursor(30, 205);
  tft.println("Set Motor RR          ->");
  tft.drawRect(10, 190, 460, 50,WHITE);
}

void DisplayInterface::displayMenuThrottle() {
  tft.setTextColor(0xFFFF);
  tft.setTextSize(3);
  tft.setCursor(30, 265);
  tft.println("Set Throttle Speed    ->");
  tft.drawRect(10, 250, 460, 50,WHITE);
}

void DisplayInterface::displayInnerMenuMotorFL(){
  tft.setTextColor(0xFFFF);
  tft.setTextSize(4);
  tft.setCursor(20, 20);
  tft.println("<");
  tft.drawRect(10, 10, 50, 50,WHITE);
  
  tft.setTextColor(0xFFFF);
  tft.setTextSize(4);
  tft.setCursor(80, 110);
  tft.println("Move Position");
  
  tft.setCursor(180, 160);
  tft.println("+");

  tft.setCursor(230, 160);
  tft.println("25");

  tft.setCursor(50, 260);
  tft.println("-");
  tft.drawRect(35, 250, 50, 50,WHITE);
  tft.setCursor(420, 260);
  tft.println("+");
  tft.drawRect(405, 250, 50, 50,WHITE);
}

void DisplayInterface::displayInnerMenuMotorFR(){
  tft.setTextColor(0xFFFF);
  tft.setTextSize(4);
  tft.setCursor(20, 20);
  tft.println("<");
  tft.drawRect(10, 10, 50, 50,WHITE);
  
  tft.setTextColor(0xFFFF);
  tft.setTextSize(4);
  tft.setCursor(80, 110);
  tft.println("Move Position");
  
  tft.setCursor(180, 160);
  tft.println("+");

  tft.setCursor(230, 160);
  tft.println("25");

  tft.setCursor(50, 260);
  tft.println("-");
  tft.drawRect(35, 250, 50, 50,WHITE);
  tft.setCursor(420, 260);
  tft.println("+");
  tft.drawRect(405, 250, 50, 50,WHITE);
}

void DisplayInterface::displayInnerMenuMotorRR(){
  tft.setTextColor(0xFFFF);
  tft.setTextSize(4);
  tft.setCursor(20, 20);
  tft.println("<");
  tft.drawRect(10, 10, 50, 50,WHITE);
  
  tft.setTextColor(0xFFFF);
  tft.setTextSize(4);
  tft.setCursor(80, 110);
  tft.println("Move Position");
  
  tft.setCursor(180, 160);
  tft.println("+");

  tft.setCursor(230, 160);
  tft.println("25");

  tft.setCursor(50, 260);
  tft.println("-");
  tft.drawRect(35, 250, 50, 50,WHITE);
  tft.setCursor(420, 260);
  tft.println("+");
  tft.drawRect(405, 250, 50, 50,WHITE);
}

void DisplayInterface::displayInnerMenuMotorRL(){
  tft.setTextColor(0xFFFF);
  tft.setTextSize(4);
  tft.setCursor(20, 20);
  tft.println("<");
  tft.drawRect(10, 10, 50, 50,WHITE);
  
  tft.setTextColor(0xFFFF);
  tft.setTextSize(4);
  tft.setCursor(80, 110);
  tft.println("Move Position");
  
  tft.setCursor(180, 160);
  tft.println("+");

  tft.setCursor(230, 160);
  tft.println("25");

  tft.setCursor(50, 260);
  tft.println("-");
  tft.drawRect(35, 250, 50, 50,WHITE);
  tft.setCursor(420, 260);
  tft.println("+");
  tft.drawRect(405, 250, 50, 50,WHITE);
}

void DisplayInterface::displayInnerMenuThrottle(){
  tft.setTextColor(0xFFFF);
  tft.setTextSize(4);
  tft.setCursor(20, 20);
  tft.println("<");
  tft.drawRect(10, 10, 50, 50,WHITE);
  
  tft.setTextColor(0xFFFF);
  tft.setTextSize(4);
  tft.setCursor(80, 110);
  tft.println("Move Position");
  
  tft.setCursor(180, 160);
  tft.println("+");

  tft.setCursor(230, 160);
  tft.println("25");

  tft.setCursor(50, 260);
  tft.println("-");
  tft.drawRect(35, 250, 50, 50,WHITE);
  tft.setCursor(420, 260);
  tft.println("+");
  tft.drawRect(405, 250, 50, 50,WHITE);
}

