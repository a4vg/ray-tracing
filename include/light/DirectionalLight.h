#ifndef DIRECTIONALLIGHT_H
#define DIRECTIONALLIGHT_H

#include "../utils/RGB.h"
#include "Light.h" // Vector3

class DirectionalLight: public Light {
public:
  RGB color;
  Vector3 direction;
  float intensity;

  DirectionalLight() {};
  DirectionalLight(RGB _color, Vector3 _direction, float _intensity);
  ~DirectionalLight() {};

  Vector3 get_direction() { return direction; };
};

#endif // DIRECTIONALLIGHT_H