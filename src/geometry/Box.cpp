#ifndef BOX_CPP
#define BOX_CPP

#include <algorithm>
#include "geometry/Box.h"

Box::Box(RGB &_color, Point3 _bound_bot, Point3 _bound_top)
: Object(_color), bound_bot(_bound_bot), bound_top(_bound_top) {};

bool Box::intersection(const Ray ray, float &t_min, Shader &sr) const {
  /**
   * Sets t to the distance between ray.origin to the intersection (p)
   * with the object. To find t:
   * 
   * https://web.cse.ohio-state.edu/~shen.94/681/Site/Slides_files/basic_algo.pdf
   **/ 

  float t_xmin = (bound_bot.x-ray.origin.x)/ray.direction.x;
  float t_xmax = (bound_top.x-ray.origin.x)/ray.direction.x;
  if (t_xmin>t_xmax) std::swap(t_xmin, t_xmax);

  float t_ymin = (bound_bot.y-ray.origin.y)/ray.direction.y;
  float t_ymax = (bound_top.y-ray.origin.y)/ray.direction.y;
  if (t_ymin>t_ymax) std::swap(t_ymin, t_ymax);

  float t_zmin = (bound_bot.z-ray.origin.z)/ray.direction.z;
  float t_zmax = (bound_top.z-ray.origin.z)/ray.direction.z;
  if (t_zmin>t_zmax) std::swap(t_zmin, t_zmax);

  float t_enter = std::max(t_xmin, std::max(t_ymin, t_zmin));
  float t_exit = std::min(t_xmax, std::min(t_ymax, t_zmax));
  if (t_enter > t_exit || t_exit<0) return false;

  t_min = t_exit;
  sr.hit_point = ray.origin + ray.direction*t_min;
  if (t_exit == t_xmax) sr.normal = Vector3(0,0,0); // intersection in x plane
  else if (t_exit == t_ymax) sr.normal = Vector3(0,0,1); // intersection in y plane
  else sr.normal = Vector3(0,0,1); // intersection in z plane
  return true;
}

#endif // BOX_CPP