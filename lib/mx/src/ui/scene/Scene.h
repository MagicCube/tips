#pragma once

#include "Component.h"
#include "ui/obj/MXObject.h"
#include "ui/screen/Screen.h"

class Scene : public Component {
 public:
  Scene() {}

  MXObject* getRoot() { return root; }

  void activate();

  void deactivate() { onDeactivate(); }

  void show() { activate(); }

 protected:
  MXObject* root;
  lv_coord_t width;
  lv_coord_t height;

  virtual void onInit();
  virtual void willDestroy();

  virtual void onActivate() {};
  virtual void onDeactivate() {};
};
