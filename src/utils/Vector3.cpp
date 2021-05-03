#ifndef VECTOR_CPP
#define VECTOR_CPP

#include <cmath>

struct Vector3 {
  float x, y, z;

  Vector3(){};
  Vector3(float _x, float _y, float _z): x(_x), y(_y), z(_z) {};
  Vector3(const Vector3& p): x(p.x), y(p.y), z(p.z) {};

  Vector3& operator=(const Vector3& p2) { x=p2.x, y=p2.y, z=p2.z; return *this; };
  Vector3 operator+(Vector3 const& p2) const { return Vector3(x+p2.x, y+p2.y, z+p2.z); };
  Vector3 operator-(Vector3 const& p2) const { return Vector3(x-p2.x, y-p2.y, z-p2.z); };

  // multiplication with scalar
  Vector3 operator*(const float s) const { return Vector3(x*s, y*s, z*s); };
  // dot product
  float operator*(const Vector3& p2) const { return x*p2.x + y*p2.y + z*p2.z; };
  // cross product
  Vector3 operator^(const Vector3& p2) const { return Vector3(y*p2.z-z*p2.y, z*p2.x-x*p2.z, x*p2.y-y*p2.x); };
  float norm() { return sqrt(x*x + y*y + z*z); };
};

#endif // VECTOR_CPP