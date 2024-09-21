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

      auto arc = lv_arc_create(root->lv_obj());
      lv_arc_set_rotation(arc, 270);
      lv_arc_set_bg_angles(arc, 0, 360);
      lv_arc_set_value(arc, 100);
      lv_obj_set_size(arc, width, height);
      lv_obj_center(arc);
      lv_obj_set_style_arc_color(arc, lv_color_hex(0x00ff00),
                                 LV_PART_INDICATOR);
      lv_obj_remove_style(arc, NULL, LV_PART_KNOB);
      lv_obj_clear_flag(arc, LV_OBJ_FLAG_CLICKABLE);
    }
  }
};
