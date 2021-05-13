#ifndef RAY_H
#define RAY_H

#include "Point3.h" // Vector

class Ray {
public:
  Point3 origin;
  Vector3 direction;

  Ray(){};
  Ray(Point3 _origin, Vector3 _direction);
  ~Ray() {};
};

#endif // RAY_H