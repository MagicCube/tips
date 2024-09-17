#pragma once

#include <lvgl.h>

#include "Component.h"
#include "ui/scene/Scene.h"

class Application : public Component {
 public:
  Application() { _current = this; }
  ~Application() {}

  static Application *getCurrent() { return _current; }

  Scene *getActiveScene() { return _activeScene; }

  void start() { onLaunch(); }

  void activateScene(Scene *scene) {
    deactivateScene();

    if (scene != nullptr) {
      _activeScene = scene;

      auto root = _activeScene->getRoot();
      lv_scr_load(root);

      scene->activate();
    }
  }

  void deactivateScene() {
    if (_activeScene != nullptr) {
      _activeScene->deactivate();
      _activeScene = nullptr;
    }
  }

 protected:
  virtual void onLaunch() {};

 private:
  static Application *_current;
  Scene *_activeScene = nullptr;
};

Application *Application::_current = nullptr;
