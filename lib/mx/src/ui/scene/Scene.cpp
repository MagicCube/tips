#include "Scene.h"

#include "ui/app/Application.h"
#include "ui/lvgl/shortcuts.h"

void Scene::activate() {
  auto activeScene = Application::getCurrent()->getActiveScene();
  if (activeScene != nullptr) {
    activeScene->deactivate();
  }

  begin();

  onActivate();
  lv_scr_load(root);

  Application::getCurrent()->setActiveScene(this);
}

void Scene::onInit() {
  root = lv_obj_create(nullptr);

  mx_size_full(root);
  mx_bg_color(root, 0x000000);
#ifdef SDL2
  mx_clip_corner(root);
  mx_rounded_full(root);
#endif
}
