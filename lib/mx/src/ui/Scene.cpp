#include "Scene.h"

#include "SceneManager.h"

void Scene::init() {
  root = lv_obj_create(NULL);
  lv_obj_set_size(root, LV_HOR_RES, LV_VER_RES);
}

void Scene::begin() {
  if (!initialized) {
    init();
    initialized = true;
  }
}

void Scene::show() { SceneManager::getInstance().activateScene(this); }
