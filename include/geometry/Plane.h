#ifndef PLANE_H
#define PLANE_H

#include "Object.h"

class Plane: public Object {
private:
  Vector3 normal;
  Point3 point;
public:
  Plane(RGB &_color, Vector3 _normal, Point3 _point);
  ~Plane(){};

  bool intersection(const Ray ray, float &t_min, Shader &sr) const;
};

#endif // PLANE_H