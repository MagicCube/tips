#pragma once

class Component {
 public:
  virtual ~Component() { willDestroy(); }

  void begin();
  void update();

 protected:
  bool initialized = false;

  virtual void onInit() {};
  virtual void willDestroy() {};

  virtual void willUpdate() {};
  virtual void onUpdate() {};
  virtual void didUpdate() {};
};
