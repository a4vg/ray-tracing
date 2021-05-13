#ifndef AMBIENTLIGHT_CPP
#define AMBIENTLIGHT_CPP

#include "light/AmbientLight.h"

AmbientLight::AmbientLight(RGB _color, float _intensity)
: Light(_color, Vector3(0,0,0), _intensity) {}


#endif // AMBIENTLIGHT_CPP