#include <Arduino.h>
#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <utility>
#include"format.h"
#include"ESP8266Client.h"

void setup() {
  Serial.begin(115200);
}

void loop() {
  // Connect to Wi-Fi
  const char* ssid = "YourWiFiSSID";
  const char* password = "YourWiFiPassword";
  IPAddress serverIP(192, 168, 1, 100);  // IP address of ESP32 server
  uint16_t serverPort = 1234;  // Port number of ESP32 server

  ESP8266Client esp8266Client(ssid, password, serverIP, serverPort);
  esp8266Client.connectToWiFi();
  esp8266Client.connectToServer();

  // Send request to server
  String request = "Hello from ESP8266";
  esp8266Client.sendRequest(request);

  // Receive response from server
  String response = esp8266Client.receiveResponse();

  // Format the data
  Format formatter;
  std::string formattedData = formatter.mergeStringAndFloat(response.c_str(), 80.765);

  // Send formatted data to Serial port
  Serial.println(formattedData.c_str());

  delay(5000);
}
