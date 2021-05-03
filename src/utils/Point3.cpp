#ifndef POINT_CPP
#define POINT_CPP

#include <cmath>
#include "Vector3.cpp"

struct Point3 {
  float x, y, z;

  Point3(){};
  Point3(float _x, float _y, float _z): x(_x), y(_y), z(_z) {};
  Point3(const Point3& p): x(p.x), y(p.y), z(p.z) {};

  Point3& operator=(const Point3& p2) { x=p2.x, y=p2.y, z=p2.z; return *this; };
  // point - point = vector (like joining the points)
  Vector3 operator-(Point3 const& p2) const { return Vector3(x-p2.x, y-p2.y, z-p2.z); };
   // point - vector = point
  Point3 operator-(Vector3 const& p2) const { return Point3(x-p2.x, y-p2.y, z-p2.z); };
  // point + vector = point
  Point3 operator+(Vector3 const& p2) const { return Point3(x+p2.x, y+p2.y, z+p2.z); };

  float norm() { return sqrt(x*x + y*y + z*z); };
};

#endif // POINT_CPP