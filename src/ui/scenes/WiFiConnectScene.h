#pragma once

#include <mx_ui.h>

static void set_angle(void *obj, int32_t v) {
  lv_arc_set_value(static_cast<lv_obj_t *>(obj), v);
}

class WiFiConnectScene : public Scene {
 protected:
  MXObject *label;

  void onInit() override {
    Scene::onInit();

    label = &mx(this)
                 ->label("Connecting to WiFi...")
                 .center()
                 .font(&lv_font_montserrat_24);

    lv_obj_t *arc = lv_arc_create(root->lv_obj());
    lv_arc_set_bg_angles(arc, 0, 360);
    lv_obj_remove_style(arc, NULL, LV_PART_KNOB);
    lv_arc_set_rotation(arc, 270);
    lv_obj_center(arc);

    lv_anim_t ani;
    lv_anim_init(&ani);
    lv_anim_set_var(&ani, arc);
    lv_anim_set_exec_cb(&ani, set_angle);
    lv_anim_set_time(&ani, 1000);
    lv_anim_set_repeat_count(&ani, LV_ANIM_REPEAT_INFINITE);
    lv_anim_set_repeat_delay(&ani, 500);
    lv_anim_set_values(&ani, 0, 100);
    lv_anim_start(&ani);
  }

  void onUpdate() override { Scene::onUpdate(); }
};
