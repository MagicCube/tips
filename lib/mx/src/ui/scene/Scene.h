#pragma once

#include <lvgl.h>

#include "Component.h"
#include "ui/screen/Screen.h"

class Scene : public Component {
 public:
  Scene() {}
  ~Scene() {}

  lv_obj_t* getRoot() { return root; }

  void activate();

  void deactivate() { onDeactivate(); }

  void show() { activate(); }

 protected:
  lv_obj_t* root;
  lv_coord_t width;
  lv_coord_t height;

  virtual void onInit();

  virtual void onActivate() {};
  virtual void onDeactivate() {};
};
