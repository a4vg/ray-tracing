#ifndef DIRECTIONALLIGHT_H
#define DIRECTIONALLIGHT_H

#include "../utils/RGB.h"
#include "Light.h" // Vector3

class DirectionalLight: public Light {
public:
  DirectionalLight() {};
  DirectionalLight(RGB _color, Vector3 _direction, float _intensity);
  ~DirectionalLight() {};

  Vector3 get_direction(Point3 &hit_point) { return direction*-1; };
  Point3 get_origin(Point3 &hit_point) { return hit_point; };
};

#endif // DIRECTIONALLIGHT_H