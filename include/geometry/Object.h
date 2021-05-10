#ifndef OBJECT_H
#define OBJECT_H

#include "../utils/Shader.h"

class Object {
public:
  RGB color;

  Object(RGB &_color);
  virtual ~Object() {};

  virtual bool intersection(const Ray ray, float &t_min, Shader &sr) const = 0;
};

#endif // OBJECT_H