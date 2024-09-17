#include "Application.h"

Application *Application::_current = nullptr;

void Application::onUpdate() {
  Component::onUpdate();

  if (_activeScene != nullptr) {
    _activeScene->update();
  }
}
