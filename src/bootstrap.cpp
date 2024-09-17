#include <mx_ui.h>

#include "ui/DefaultScene.h"

void bootstrap() {
  static Scene *defaultScene = new DefaultScene();
  defaultScene->begin();
  defaultScene->show();
}
