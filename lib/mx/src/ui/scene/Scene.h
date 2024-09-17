#pragma once

#include <lvgl.h>

#include "Component.h"
#include "ui/screen/Screen.h"

class Scene : public Component {
 public:
  Scene() {}
  ~Scene() {}

  lv_obj_t* getRoot() { return root; }

  void activate() { onActivate(); }

  void deactivate() { onDeactivate(); }

 protected:
  lv_obj_t* root;
  lv_coord_t width;
  lv_coord_t height;

  virtual void onInit() {
    root = lv_obj_create(nullptr);

    width = Screen::getMain()->getWidth();
    height = Screen::getMain()->getHeight();

    lv_obj_set_size(root, width, height);
    lv_obj_set_style_bg_color(root, lv_color_black(), LV_PART_MAIN);
#ifdef SDL2
    lv_obj_set_style_clip_corner(root, true, 0);
    lv_obj_set_style_radius(root, LV_RADIUS_CIRCLE, 0);
#endif
  };

  virtual void onActivate() {};
  virtual void onDeactivate() {};
};
