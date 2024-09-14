#pragma once

#include <lvgl.h>

#include "Updatable.h"

class Scene : public Updatable {
 public:
  Scene() { initialized = false; }

  virtual ~Scene() { lv_obj_del(root); }

  lv_obj_t* getRoot() { return root; }

  virtual void begin();

  virtual void init() = 0;

  virtual void update() = 0;

  virtual void activate() {}

  virtual void deactivate() {}

 protected:
  bool initialized;
  lv_obj_t* root;
};
