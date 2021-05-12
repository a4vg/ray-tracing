#ifndef AMBIENTLIGHT_H
#define AMBIENTLIGHT_H

#include "../utils/RGB.h"
#include "Light.h" // Vector3

class AmbientLight: public Light {
public:
  AmbientLight() {};
  AmbientLight(RGB _color, Vector3 _direction, float _intensity);
  ~AmbientLight() {};

  Vector3 get_direction(Point3 &hit_point) { return Vector3(0,0,0); };
};

#endif // AMBIENTLIGHT_H