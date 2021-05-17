#ifndef DIRECTIONALLIGHT_CPP
#define DIRECTIONALLIGHT_CPP

#include "light/DirectionalLight.h"
#include "utils/Ray.h"
#include "geometry/Object.h"
#include "utils/Shader.h"

DirectionalLight::DirectionalLight(RGB _color, Vector3 _direction, float _intensity)
: Light(_color, _direction, _intensity) {}

bool DirectionalLight::is_shadow(std::vector<std::shared_ptr<Object>> objects_p, std::shared_ptr<Shader> sr) {
  Ray shadow_ray(sr->hit_point + sr->normal*1e-2, get_direction(sr->hit_point));
  float temp;
  for (auto obj_p : objects_p) {
    if (obj_p->intersection(shadow_ray, temp)) return true;
  }
  return false;
}


#endif // DIRECTIONALLIGHT_CPP