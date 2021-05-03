#ifndef SPHERE_CPP
#define SPHERE_CPP

#include "Object.cpp"

class Sphere: public Object {
private:
  float radius;
  Point3 center;
public:
  Sphere(RGB &_color, Point3 _center, float _radius);
  ~Sphere() {};

  bool intersection(const Ray ray, float &t_min) const;
};

inline Sphere::Sphere(RGB &_color, Point3 _center, float _radius)
: Object(_color), center(_center), radius(_radius) {}

inline bool Sphere::intersection(const Ray ray, float &t_min) const {
  /**
   * Sets t to the distance between ray.origin to the intersection
   * with the object. To find t: 
   * at^2 + bt + c = 0, where (• is dot product)
   *      a = d•d               <-- d is ray.direction
   *      b = 2d•(o-c)          <-- o is ray.origin, c is this.center
   *      c = (o-c)•(o-c)-r^2   <-- r is radius
   * t = (-b +- sqrt(b^2 - 4ac)) / 2a
   * d = b^2 - 4ac              <-- d<0 no hit, d=0 one hit,
   *                                d>0 two hits (in and out of the sphere)
   **/ 
  const float k_epsilon = 1e-8;

  float a = ray.direction*ray.direction;
  float b = (ray.direction*2.0f) * (ray.origin-center);
  float c = (ray.origin-center) * (ray.origin-center) - radius*radius;

  float discriminant = b*b - 4*a*c;

  // No intersections
  if (discriminant < 0) return false;

  float e = sqrt(discriminant);

  // at two intersections
  float smaller_root = (-b-e)/(2.0*a);
  if (smaller_root > k_epsilon) {
    t_min = smaller_root;
    return true;
  }

  float larger_root = (-b+e)/(2.0*a);
  if (larger_root > k_epsilon) {
    t_min = larger_root;
    return true;
  }

  // one intersection (d ≈ 0)
  return false;
}

#endif // SPHERE_CPP