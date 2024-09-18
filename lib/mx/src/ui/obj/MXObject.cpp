#include "MXObject.h"

#include "ui/scene/Scene.h"

MXObject* mx(lv_obj_t* obj) { return new MXObject(obj); }
MXObject* mx(MXObject* obj) { return new MXObject(obj->lv_obj()); }
MXObject* mx(Scene* scene) { return mx(scene->getRoot()); }
MXObject* mx() { return mx(lv_obj_create(nullptr)); }
