#pragma once

#include <SPIFFS.h>
#include <mx_ui.h>

#include "fonts.h"

class TestScene : public Scene {
 protected:
  void onInit() {
    Scene::onInit();

    auto img = lv_img_create(root);
    mx_img(img, "A:/image.jpg");
    mx_center(img);

    auto label = lv_label_create(root);
    mx_text_color(label, 0x520404);

    mx_text(label, "19:38");
    mx_center_x(label);
    mx_top(label, 44);
    mx_font(label, 72);
  }
};
