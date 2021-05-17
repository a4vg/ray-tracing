#ifndef POINTLIGHT_CPP
#define POINTLIGHT_CPP

#include "light/PointLight.h"
#include "utils/Ray.h"
#include "geometry/Object.h"
#include "utils/Shader.h"

PointLight::PointLight(RGB _color, Point3 _origin, float _intensity)
: Light(_color, Vector3(0,0,0), _intensity), origin(_origin) {}

bool PointLight::is_shadow(std::vector<std::shared_ptr<Object>> objects_p, std::shared_ptr<Shader> sr) {
  Ray shadow_ray(sr->hit_point + sr->normal*1e-2, get_direction(sr->hit_point));

  float ray_d = (shadow_ray.origin - origin).length();
  float t;
  for (auto obj_p : objects_p) {
    if (obj_p->intersection(shadow_ray, t) && t<ray_d) return true;
  }
  return false;
}

#endif // POINTLIGHT_CPP