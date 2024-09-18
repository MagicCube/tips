#include "Scene.h"

#include "ui/app/Application.h"

void Scene::activate() {
  auto activeScene = Application::getCurrent()->getActiveScene();
  if (activeScene != nullptr) {
    activeScene->deactivate();
  }

  begin();

  onActivate();
  lv_scr_load(root->lv_obj());

  Application::getCurrent()->setActiveScene(this);
}

void Scene::onInit() {
  root = mx()->size_full().bg_color(0x000000).ptr();
#ifdef SDL2
  root->clip_corner().rounded_full();
#endif
}

void Scene::willDestroy() {
  Scene::willDestroy();
  delete root;
  root = nullptr;
}
