#pragma once

#include <hal/wifi/WiFiConnection.h>
#include <mx_ui.h>

#include <algorithm>

class WiFiConnectScene : public Scene {
 protected:
  MXObject *label;

  void onInit() override {
    Scene::onInit();

    auto connection = WiFiConnection::singleton();
    connection->begin("Henry's iPhone 14 Pro", "13913954971");

    label = &mx(this)
                 ->label("Connecting to WiFi...")
                 .center()
                 .font(&lv_font_montserrat_24);

    mx(this)->spinner();
  }

  void onUpdate() override {
    Scene::onUpdate();
    auto connection = WiFiConnection::singleton();
    if (connection->isConnected()) {
      label->text("Connected");
    }
  }
};
