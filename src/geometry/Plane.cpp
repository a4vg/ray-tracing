#ifndef PLANE_CPP
#define PLANE_CPP

#include "geometry/Plane.h"

Plane::Plane(RGB &_color, Vector3 _normal, Point3 _point)
: Object(_color), normal(_normal), point(_point) {};

bool Plane::intersection(const Ray ray, float &t_min, Shader &sr) const {
  /**
   * Sets t to the distance between ray.origin to the intersection (p)
   * with the object. To find t: 
   * Plane equation: (p-a)*n = 0      <-- a is plane.point, n is plane.normal
   * Ray equation: p = o+td           <-- o is ray.origin, d is ray.direction
   * Replacing p:
   *    t = (a-o)*n / (d*n)       <-- t=INF no hit, t<0 no hit, t>0 one hit
   **/ 
  const float k_epsilon = 1e-8;

  float t = ((point-ray.origin)*normal) / (ray.direction*normal);

  if (t>k_epsilon) {
    t_min = t;
    sr.hit_point = ray.origin + ray.direction*t_min;
    sr.normal = normal;
    return true;
  }
  return false;
}

#endif // PLANE_CPP