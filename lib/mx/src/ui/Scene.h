#pragma once

#include <lvgl.h>

#include "Updatable.h"

class Scene : public Updatable {
 public:
  Scene() {
    initialized = false;
    root = lv_obj_create(NULL);
    lv_obj_set_size(root, LV_HOR_RES, LV_VER_RES);
  }

  virtual ~Scene() { lv_obj_del(root); }

  bool isInitialized() { return initialized; }

  lv_obj_t* getRoot() { return root; }

  virtual void begin() {
    if (!initialized) {
      init();
      initialized = true;
    }
  }

  virtual void init() = 0;

  virtual void update() = 0;

  virtual void activate() {}

  virtual void deactivate() {}

 protected:
  bool initialized;
  lv_obj_t* root;
};
