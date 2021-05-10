#ifndef DIRECTIONALLIGHT_CPP
#define DIRECTIONALLIGHT_CPP

#include "light/DirectionalLight.h"

DirectionalLight::DirectionalLight(RGB _color, Vector3 _direction, float _intensity)
: color(_color), direction(_direction), intensity(_intensity) {}


#endif // DIRECTIONALLIGHT_CPP