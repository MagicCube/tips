#include <mx_ui.h>

#include "ui/DefaultScene.h"

void mx_bootstrap() {
  static Scene *defaultScene = new DefaultScene();
  defaultScene->begin();
  defaultScene->show();
}
