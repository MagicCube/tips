#include "SceneManager.h"

Scene* SceneManager::_activeScene = nullptr;

void SceneManager::activateScene(Scene* scene) {
  deactivateScene();

  _activeScene = scene;

  if (_activeScene != nullptr) {
    lv_scr_load(_activeScene->getRoot());
    _activeScene->activate();
  }
}

void SceneManager::deactivateScene() {
  if (_activeScene != nullptr) {
    _activeScene->deactivate();
    _activeScene = nullptr;
  }
}
