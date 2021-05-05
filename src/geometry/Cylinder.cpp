#ifndef CYLINDER_CPP
#define CYLINDER_CPP

#include <iostream>
#include "Object.cpp"

class Cylinder: public Object {
private:
  float radius;
  Point3 center;
  float y_start;
  float y_end;
public:
  Cylinder(RGB &_color, Point3 _center, float _y_start, float _y_end, float _radius);
  ~Cylinder() {};

  bool intersection(const Ray ray, float &t_min) const;
};

inline Cylinder::Cylinder(RGB &_color, Point3 _center, float _y_start, float _y_end, float _radius)
: Object(_color), center(_center), y_start(_y_start), y_end(_y_end), radius(_radius) {}

inline bool Cylinder::intersection(const Ray ray, float &t_min) const {
  /**
   * Sets t to the distance between ray.origin to the intersection
   * with the object. To find t:
   * Cylinder equation: p_x^2 + p_z^2 = r^2, 
   * Ray equation: p = o+td
   * Replacing p:
   * at^2 + bt + c = 0, where (• is dot product)
   *      a = d•d               <-- d is ray.direction
   *      b = 2d•(o-c)          <-- o is ray.origin, c is this.center
   *      c = (o-c)•(o-c)-r^2   <-- r is radius
   * t = (-b +- sqrt(b^2 - 4ac)) / 2a
   * d = b^2 - 4ac              <-- d<0 no hit, d=0 one hit,
   *                                d>0 two hits (in and out of the Cylinder)
   * SAME AS SPHERE BUT z IS IGNORED. POINTS MUST BE CONSIDERED AS 2D (z=0)
   **/
  const float k_epsilon = 1e-8;

  Vector3 ray_direction2d(ray.direction);
  ray_direction2d.y = 0;
  Point3 ray_origin2d(ray.origin);
  ray_origin2d.y = 0;
  Point3 center2d(center);
  center2d.y = 0;

  float a = ray_direction2d*ray_direction2d;
  float b = (ray_direction2d*2.0f) * (ray_origin2d-center2d);
  float c = (ray_origin2d-center2d) * (ray_origin2d-center2d) - radius*radius;

  float discriminant = b*b - 4*a*c;

  // No intersections
  if (discriminant < 0) return false;

  float e = sqrt(discriminant);

  // at two intersections
  float smaller_root = (-b-e)/(2.0*a);
  if (smaller_root > k_epsilon) {
    float y_intersect = ray.origin.y + smaller_root*ray.direction.y - center.y;
    if ((y_start<y_intersect && y_intersect<y_end) || (y_end<y_intersect && y_intersect<y_start)) {
      t_min = smaller_root;
      return true;
    }
  }

  float larger_root = (-b+e)/(2.0*a);
  if (larger_root > k_epsilon) {
    float y_intersect = ray.origin.y + larger_root*ray.direction.y - center.y;
    t_min = larger_root;
    if ((y_start<y_intersect && y_intersect<y_end) || (y_end<y_intersect && y_intersect<y_start)) {
      t_min = larger_root;
      return true;
    }
  }

  // one intersection (d ≈ 0)
  return false;
}

#endif // CYLINDER_CPP