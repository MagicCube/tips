#pragma once

#include "Scene.h"

class SceneManager {
 public:
  static Scene* getActiveScene() { return _activeScene; }
  static void activateScene(Scene* scene);
  static void deactivateScene();

 private:
  SceneManager() {}
  ~SceneManager() {}

  SceneManager(const SceneManager&) = delete;
  SceneManager& operator=(const SceneManager&) = delete;

  static Scene* _activeScene;
};
