#pragma once

#include <SPIFFS.h>
#include <mx_ui.h>

#include "fonts.h"

class TestScene : public Scene {
 protected:
  lv_obj_t *label;

  void onInit() override {
    Scene::onInit();

    auto img = lv_img_create(root);
    mx_img(img, "A:/watch_face_001.jpg");
    mx_center(img);

    label = lv_label_create(root);
    mx_text_color(label, 0x520404);

    mx_text(label, "19:38");
    mx_center_x(label);
    mx_top(label, 44);
    mx_font(label, 72);
  }

  void onUpdate() override {
    Scene::onUpdate();

    mx_text_fmt(label, "%d", millis() / 1000);
  }
};
