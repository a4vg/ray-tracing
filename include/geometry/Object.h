#ifndef OBJECT_H
#define OBJECT_H

#include <memory>

#include "utils/Shader.h"
#include "materials/Material.h"

class Object {
public:
  RGB color;
  std::shared_ptr<Material> material;

  Object(RGB &_color, std::shared_ptr<Material> _material);
  virtual ~Object() {};

  virtual bool intersection(const Ray ray, float &t_min, std::shared_ptr<Shader> sr=nullptr) const = 0;
  RGB shade(Shader &sr);
};

#endif // OBJECT_H