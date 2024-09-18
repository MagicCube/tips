#pragma once

#include <mx_ui.h>

#include "fonts.h"

class TestScene : public Scene {
 protected:
  lv_obj_t *label;

  void onInit() override {
    Scene::onInit();

    mx(this).image("A:/watch_face_001.jpg").center();

    label = mx(this).label().text_color(0x520404).font(72).center_x().top(44).self();
  }

  void onUpdate() override {
    Scene::onUpdate();

    mx_text_fmt(label, "%d", 100);
  }
};
