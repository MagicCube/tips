#pragma once

class Component {
 public:
  virtual ~Component() { willDestroy(); }

  void begin() { onInit(); };

  void update() {
    willUpdate();
    onUpdate();
    didUpdate();
  }

 protected:
  virtual void onInit() {};
  virtual void willDestroy() {};

  virtual void willUpdate() {};
  virtual void onUpdate() {};
  virtual void didUpdate() {};
};
