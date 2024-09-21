#include "Scene.h"

#include <lvgl.h>

#include "ui/app/Application.h"

void Scene::activate() {
  auto activeScene = Application::current()->getActiveScene();
  if (activeScene != nullptr) {
    activeScene->deactivate();
  }

  begin();

  onActivate();
  lv_scr_load(root->lv_obj());

  Application::current()->setActiveScene(this);
}

void Scene::onInit() {
  Component::onInit();
  root = &mx()->size_full().bg_color(0x000000);
  width = lv_obj_get_width(root->lv_obj());
  height = lv_obj_get_height(root->lv_obj());
#ifdef SDL2
  root->clip_corner().rounded_full();
#endif
}

void Scene::willDestroy() {
  Scene::willDestroy();
  delete root;
  root = nullptr;
}
