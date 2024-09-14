#pragma once

#include "Scene.h"

class SceneManager {
 public:
  static SceneManager& getInstance() {
    static SceneManager instance;
    return instance;
  }

  Scene* getCurrentScene() { return _currentScene; }
  void setScene(Scene* scene);

 private:
  SceneManager() : _currentScene(nullptr) {}
  ~SceneManager() {}

  SceneManager(const SceneManager&) = delete;
  SceneManager& operator=(const SceneManager&) = delete;

  Scene* _currentScene;
};
