#ifndef ESP8266CLIENT_H
#define ESP8266CLIENT_H

#include <ESP8266WiFi.h>
#include <WiFiClient.h>

class ESP8266Client {
public:
  ESP8266Client(const char* ssid, const char* password, IPAddress serverIP, uint16_t serverPort);
  void connectToWiFi();
  void connectToServer();
  void sendRequest(String data);
  String receiveResponse();

private:
  const char* ssid_;
  const char* password_;
  IPAddress serverIP_;
  uint16_t serverPort_;
  WiFiClient client_;
};

#endif