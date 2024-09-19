#pragma once

#include <mx_ui.h>

#include "fonts.h"

class TestScene : public Scene {
 protected:
  MXObject *label;

  void onInit() override {
    Scene::onInit();

    mx(this)->image("A:/watch_face_001.jpg").center();

    label = &mx(this)->label().text_color(0x520404).center_x().y(44).font(&lv_font_montserrat_72);
  }

  void onUpdate() override {
    Scene::onUpdate();

    label->text("20:56");
  }
};
