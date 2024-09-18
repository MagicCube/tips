#pragma once

#include <Component.h>
#include <NTPClient.h>
#include <WiFiUdp.h>

class WiFiTimeClient : public Component {
 public:
  WiFiTimeClient() : timeClient(ntpUDP, "ntp.aliyun.com", 3600 * 8) {}

  static WiFiTimeClient& getInstance() {
    static WiFiTimeClient instance;
    return instance;
  }

  String getFormattedTime() { return timeClient.getFormattedTime(); }

 protected:
  WiFiUDP ntpUDP;
  NTPClient timeClient;

  void onInit() override {
    Component::onInit();

    timeClient.begin();
  }

  void onUpdate() override {
    Component::onUpdate();

    timeClient.update();
  }
};
