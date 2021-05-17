#ifndef POINTLIGHT_H
#define POINTLIGHT_H

#include "../utils/RGB.h"
#include "Light.h" // Vector3

class PointLight: public Light {
public:
  Point3 origin;

  PointLight() {};
  PointLight(RGB _color, Point3 _origin, float _intensity);
  ~PointLight() {};

  Vector3 get_direction(Point3 &hit_point) { return (origin - hit_point).get_unit_vector(); }; // from hit point to origin
  bool is_shadow(std::vector<std::shared_ptr<Object>> objects_p, std::shared_ptr<Shader> sr);
};

#endif // POINTLIGHT_H