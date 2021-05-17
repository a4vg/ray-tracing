#ifndef RAY_CPP
#define RAY_CPP

#include "utils/Ray.h"

Ray::Ray(Point3 _origin, Vector3 _direction)
: origin(_origin), direction(_direction) {}

void Ray::operator=(const Ray &ray) {
  origin = ray.origin;
  direction = ray.direction;
}

#endif // RAY_CPP