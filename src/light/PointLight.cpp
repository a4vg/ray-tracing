#ifndef POINTLIGHT_CPP
#define POINTLIGHT_CPP

#include "light/PointLight.h"

PointLight::PointLight(RGB _color, Point3 _origin, float _intensity)
: Light(_color, Vector3(0,0,0), _intensity), origin(_origin) {}


#endif // POINTLIGHT_CPP