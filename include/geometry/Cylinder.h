#ifndef CYLINDER_H
#define CYLINDER_H

#include "Object.h"

class Cylinder: public Object {
private:
  float radius;
  Point3 center;
  float y_start;
  float y_end;
public:
  Cylinder(RGB &_color, std::shared_ptr<Material> _material, Point3 _center, float _y_start, float _y_end, float _radius);
  ~Cylinder() {};

  bool intersection(const Ray ray, float &t_min, std::shared_ptr<Shader> sr) const;
};

#endif // CYLINDER_H