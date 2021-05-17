#ifndef BOX_H
#define BOX_H

#include "Object.h"

class Box: public Object {
private:
  Point3 bound_bot;
  Point3 bound_top;
public:
  Box(RGB &_color, std::shared_ptr<Material> _material, Point3 _bound_bot, Point3 _bound_top);
  ~Box(){};

  bool intersection(const Ray ray, float &t_min, std::shared_ptr<Shader> sr) const;
};

#endif // BOX_H