#pragma once

#include "Component.h"
#include "ui/scene/Scene.h"

class Application : public Component {
 public:
  Application() { _current = this; }
  ~Application() {}

  static Application *getCurrent() { return _current; }

  Scene *getActiveScene() { return _activeScene; }

  void start() {
    begin();
    onLaunch();
  }

 protected:
  void setActiveScene(Scene *scene) { _activeScene = scene; }

  virtual void onLaunch() {};

 private:
  static Application *_current;
  Scene *_activeScene = nullptr;

  friend class Scene;
};
