#pragma once

#include <mx_ui.h>

class TestScene : public Scene {
 protected:
  void onInit() {
    Scene::onInit();
    auto *button = lv_btn_create(root);
    mx_center(button);

    auto *buttonLabel = lv_label_create(button);
    mx_text(buttonLabel, "Test");
    mx_center(buttonLabel);
  }
};
