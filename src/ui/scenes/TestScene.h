#pragma once

#include <SPIFFS.h>
#include <mx_ui.h>

#include "fonts.h"

class TestScene : public Scene {
 protected:
  void onInit() {
    Scene::onInit();

    auto img = lv_img_create(root);
    lv_img_set_src(img, "A:/test.jpg");
    mx_center(img);

    auto label = lv_label_create(root);
    mx_text(label, "19:38");
    mx_font(label, 72);
    mx_center(label);
  }
};
