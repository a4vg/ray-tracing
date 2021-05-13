#ifndef OBJECT_H
#define OBJECT_H

#include <memory>

#include "../utils/Shader.h"

class Object {
public:
  RGB color;

  Object(RGB &_color);
  virtual ~Object() {};

  virtual bool intersection(const Ray ray, float &t_min, std::shared_ptr<Shader> sr=nullptr) const = 0;
};

#endif // OBJECT_H