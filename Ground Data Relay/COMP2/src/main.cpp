#include<Arduino.h>
#include"drivers/_motors.h"
#include"drivers/MotorController.h"
#include <iostream>
#include "StringParser.h"

#define THROTTLE_PIN 2

MotorController motor(THROTTLE_PIN);

void setup(){
    Serial.begin(9600);
    motor.begin();
}

void loop(){
    ServoController *mov = new ServoController();

    std::string values[] = {"MOTOR-FL", "MOTOR-FR", "MOTOR-RR", "MOTOR-RL", "IMU", "GPS", "THROTTLE"};
    std::string input = "MOTOR-FL:90";

    StringParser parser(input);
    parser.parse();

    std::string extractedString = parser.getExtractedString();
    int extractedNumber = parser.getExtractedNumber();
    if(extractedString == values[0]){
        mov -> moveToAngleFL(extractedNumber);
    }
    if(extractedString == values[1]){
        mov -> moveToAngleFR(extractedNumber);
    }
    if(extractedString == values[2]){
        mov -> moveToAngleRR(extractedNumber);
    }
    if(extractedString == values[3]){
        mov -> moveToAngleRL(extractedNumber);
    }
    if(extractedString == values[4]){

    }
    if(extractedString == values[5]){

    }
    if(extractedString == values[6]){
        motor.setThrottle(extractedNumber);
    }
    delete mov;
}