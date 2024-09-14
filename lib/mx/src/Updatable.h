class Updatable {
 public:
  virtual void begin() {};
  virtual void update() = 0;
  virtual ~Updatable() {}
};
