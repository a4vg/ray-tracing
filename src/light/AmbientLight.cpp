#ifndef AMBIENTLIGHT_CPP
#define AMBIENTLIGHT_CPP

#include "light/AmbientLight.h"

AmbientLight::AmbientLight(RGB _color, Vector3 _direction, float _intensity)
: Light(_color, _direction, _intensity) {}


#endif // AMBIENTLIGHT_CPP