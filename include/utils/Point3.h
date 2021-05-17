#ifndef POINT_H
#define POINT_H

#include <cmath>
#include "Vector3.h"

struct Point3 {
  float x, y, z;

  Point3(){};
  Point3(float _x, float _y, float _z): x(_x), y(_y), z(_z) {};

  Point3(const Point3& p): x(p.x), y(p.y), z(p.z) {};

  void operator=(const Point3& p2) { x=p2.x, y=p2.y, z=p2.z; };
  // point - point = vector (like joining the points)
  Vector3 operator-(Point3 const& p2) const { return Vector3(x-p2.x, y-p2.y, z-p2.z); };
   // point - vector = point
  Point3 operator-(Vector3 const& p2) const { return Point3(x-p2.x, y-p2.y, z-p2.z); };
  // point + vector = point
  Point3 operator+(Vector3 const& p2) const { return Point3(x+p2.x, y+p2.y, z+p2.z); };

  friend bool operator> (Point3 &p1, const Point3 &p2) { return p1.x>p2.x && p1.y>p2.y && p1.z>p2.z; };
  friend bool operator<= (Point3 &p1, const Point3 &p2) { return p1.x<=p2.x && p1.y<=p2.y && p1.z<=p2.z; };;

  friend bool operator< (Point3 &p1, const Point3 &p2) { return p1.x<p2.x && p1.y<p2.y && p1.z<p2.z; };;
  friend bool operator>= (Point3 &p1, const Point3 &p2) { return p1.x>=p2.x && p1.y>=p2.y && p1.z>=p2.z; };;

  float norm() { return sqrt(x*x + y*y + z*z); };
};

#endif // POINT_H