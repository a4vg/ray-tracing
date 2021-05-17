#ifndef OBJECT_CPP
#define OBJECT_CPP

#include <memory>

#include "geometry/Object.h"

Object::Object(RGB &_color, std::shared_ptr<Material> _material)
: color(_color), material(_material) {};

RGB Object::shade(Shader &sr) {
  return material->shade(sr);
};

#endif // OBJECT_CPP