#ifndef OBJECT_CPP
#define OBJECT_CPP

#include <memory>

#include "../utils/Point3.cpp"
#include "../utils/RGB.cpp"
#include "../utils/Ray.cpp"

class Object {
public:
  RGB color;

  Object(RGB &_color);
  virtual ~Object() {};

  virtual bool intersection(const Ray ray) const = 0;
};

inline Object::Object(RGB &_color)
: color(_color) {};

#endif // OBJECT_CPP