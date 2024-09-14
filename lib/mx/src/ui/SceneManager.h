#pragma once

#include "Scene.h"

class SceneManager {
 public:
  static SceneManager& getInstance() {
    static SceneManager instance;
    return instance;
  }

  Scene* getActiveScene() { return _activeScene; }
  void activateScene(Scene* scene);
  void deactivateScene();

 private:
  SceneManager() {}
  ~SceneManager() {}

  SceneManager(const SceneManager&) = delete;
  SceneManager& operator=(const SceneManager&) = delete;

  Scene* _activeScene;
};
