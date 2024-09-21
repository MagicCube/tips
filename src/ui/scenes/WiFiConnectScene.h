#pragma once

#include <hal/wifi/WiFiConnection.h>
#include <mx_ui.h>

#include <algorithm>

class WiFiConnectScene : public Scene {
 protected:
  MXObject *label;
  MXObject *spinner;

  void onInit() override {
    Scene::onInit();

    auto connection = WiFiConnection::singleton();
    connection->begin("Henry's iPhone 14 Pro", "13913954971");

    label = &mx(this)
                 ->label("Connecting to WiFi...")
                 .center()
                 .font(&lv_font_montserrat_24);

    spinner = &mx(this)->spinner();
  }

  void onActivate() override {
    Scene::onActivate();
    spinner->show();
  }

  void onUpdate() override {
    Scene::onUpdate();
    auto connection = WiFiConnection::singleton();
    if (connection->isConnected()) {
      label->text("Connected");

      if (spinner) {
        spinner->hide();
        delete spinner;
        spinner = nullptr;
      }

      mx(this)->arc().size_full().arc_color(0x00ff00).arc_value(100);
    }
  }
};
