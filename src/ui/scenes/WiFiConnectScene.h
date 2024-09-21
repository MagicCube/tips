#pragma once

#include <hal/wifi/WiFiConnection.h>
#include <mx_ui.h>

#include <algorithm>

class WiFiConnectScene : public Scene {
 protected:
  void onInit() override {
    Scene::onInit();

    mx(this)
        ->label("Connecting to WiFi...")
        .center()
        .font(&lv_font_montserrat_24);

    mx(this)->spinner();
  }

  void onUpdate() override {
    Scene::onUpdate();
    WiFiConnection::singleton()->checkConnection();
  }
};
