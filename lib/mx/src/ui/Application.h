#pragma once

#include <lvgl.h>

#include "Updatable.h"

class Application : public Updatable {
 public:
  Application() {}
  ~Application() {}

  void begin() override { onInit(); }
  void update() override { onUpdate(); }

  void start() { onLaunch(); }

 protected:
  lv_obj_t *root;

  virtual void onInit() {
    root = lv_obj_create(nullptr);
    auto width = lv_obj_get_width(lv_scr_act());
    auto height = lv_obj_get_height(lv_scr_act());
    lv_obj_set_size(root, width, height);
    lv_obj_set_style_clip_corner(root, true, 0);
    lv_obj_set_style_bg_color(root, lv_color_black(), LV_PART_MAIN);
    lv_obj_set_style_radius(root, LV_RADIUS_CIRCLE, 0);
    lv_obj_clear_flag(root, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_set_scrollbar_mode(root, LV_SCROLLBAR_MODE_OFF);
  };

  virtual void onLaunch() { lv_scr_load(root); };

  virtual void onUpdate() {};
};
