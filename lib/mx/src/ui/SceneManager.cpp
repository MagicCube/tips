#include "SceneManager.h"

void SceneManager::setScene(Scene* scene) {
  if (_currentScene != nullptr) {
    _currentScene->deactivate();
    _currentScene = nullptr;
  }

  _currentScene = scene;
  if (_currentScene != nullptr) {
    if (!_currentScene->isInitialized()) {
      _currentScene->init();
    }
    lv_scr_load(_currentScene->getRoot());
    _currentScene->activate();
  }
}
