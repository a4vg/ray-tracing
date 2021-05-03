#ifndef PLANE_CPP
#define PLANE_CPP

#include "Object.cpp"

class Plane: public Object {
private:
  Vector3 normal;
  Point3 point;
public:
  Plane(RGB &_color, Vector3 _normal, Point3 _point);
  ~Plane(){};

  bool intersection(const Ray ray, float &t_min) const;
};

inline Plane::Plane(RGB &_color, Vector3 _normal, Point3 _point)
: Object(_color), normal(_normal), point(_point) {};

inline bool Plane::intersection(const Ray ray, float &t_min) const {
  /**
   * Sets t to the distance between ray.origin to the intersection (p)
   * with the object. To find t: 
   * Plane equation: (p-a)*n      <-- a is plane.point, n is plane.normal
   * Ray equation: o+td           <-- o is ray.origin, d is ray.direction
   * Replacing p:
   *    t = (a-o)*n / (d*n)       <-- t=INF no hit, t<0 no hit, t>0 one hit
   **/ 
  const float k_epsilon = 1e-8;

  float t = ((point-ray.origin)*normal) / (ray.direction*normal);

  if (t>k_epsilon) {
    t_min = t;
    return true;
  }
  return false;
}

#endif // PLANE_CPP