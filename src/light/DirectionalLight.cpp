#ifndef DIRECTIONALLIGHT_CPP
#define DIRECTIONALLIGHT_CPP

#include "light/DirectionalLight.h"

DirectionalLight::DirectionalLight(RGB _color, Vector3 _direction, float _intensity)
: Light(_color, _direction, _intensity) {}


#endif // DIRECTIONALLIGHT_CPP