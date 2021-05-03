#ifndef RAY_CPP
#define RAY_CPP

#include "Point3.cpp"
#include "Vector3.cpp"

class Ray {
public:
  Point3 origin;
  Vector3 direction;

  Ray(){};
  Ray(Point3& _origin, Vector3& _direction);
  ~Ray() {};
};

inline Ray::Ray(Point3& _origin, Vector3& _direction)
: origin(_origin), direction(_direction) {}

#endif // RAY_CPP