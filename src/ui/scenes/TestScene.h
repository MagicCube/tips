#pragma once

#include <mx_ui.h>

class TestScene : public Scene {
 protected:
  void onInit() {
    Scene::onInit();
    lv_obj_t *button = lv_btn_create(root);
    mx_size(button, 100, 100);
    mx_center(button);
  }
};
