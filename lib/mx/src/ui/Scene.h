#pragma once

#include <lvgl.h>

#include "Updatable.h"

class Scene : public Updatable {
 public:
  Scene() { initialized = false; }

  virtual ~Scene() { lv_obj_del(root); }

  lv_obj_t* getRoot() { return root; }

  virtual void begin();

  virtual void init();

  virtual void show();

  virtual void update() {};

  void activate() { this->onActivate(); }
  void deactivate() { this->onDeactivate(); }

 protected:
  bool initialized;
  lv_obj_t* root;

  virtual void onActivate() {}
  virtual void onDeactivate() {}
};
