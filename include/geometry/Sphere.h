#ifndef SPHERE_H
#define SPHERE_H

#include "Object.h"

class Sphere: public Object {
private:
  float radius;
  Point3 center;
public:
  Sphere(RGB &_color, Point3 _center, float _radius);
  ~Sphere() {};

  bool intersection(const Ray ray, float &t_min, std::shared_ptr<Shader> sr) const;
};

#endif // SPHERE_H