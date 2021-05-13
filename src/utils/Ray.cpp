#ifndef RAY_CPP
#define RAY_CPP

#include "utils/Ray.h"

Ray::Ray(Point3 _origin, Vector3 _direction)
: origin(_origin), direction(_direction) {}

#endif // RAY_CPP