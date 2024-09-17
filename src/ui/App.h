#pragma once

#include <mx_ui.h>

class App : public Application {
 protected:
  void onInit() override {
    Application::onInit();
    lv_obj_t *button = lv_btn_create(root);
    lv_obj_set_size(button, 100, 100);
    lv_obj_center(button);
    lv_obj_set_style_bg_color(button, lv_color_hex(0x0000ff), 0);
  }

  void onLaunch() override { Application::onLaunch(); }
};
