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

  void hide() { deactivate(); }

  void update() {
    if (root) {
      Component::update();
    }
  }

 protected:
  MXObject* root;
  lv_coord_t width;
  lv_coord_t height;

  virtual bool shouldDestroy() { return false; }

  virtual void onInit();
  virtual void willDestroy();

  virtual void onActivate() {};
  virtual void onDeactivate() {};
};
