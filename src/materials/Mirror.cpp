#ifndef MIRROR_CPP
#define MIRROR_CPP

#include "materials/Mirror.h"
#include "World.h"

#include <cmath>

Vector3 reflected_dir(Vector3 &ray_dir, Vector3 &normal) {
    return ray_dir - normal * 2.f * (ray_dir*normal);
}

RGB Mirror::shade(Shader &sr) {
  /**
   * Cast a ray from the hit point in inverted direction
   * and add the color to the final results
   **/

  Ray reflec_ray(sr.hit_point+ sr.normal*1e-3, reflected_dir(sr.ray_casted.direction, sr.normal));
  RGB reflec_color = sr.world->hit(reflec_ray);

  float diff_coef = .9;
  float spec_coef = .5;
  float spec_exp = 70;
  float L = diff_coef * sr.world->ambient_light.intensity;

  if (sr.obj_p) { // check if ray hit something
    for (auto light : sr.world->lights) {
      float n_dir = sr.normal*light->get_direction(sr.hit_point);

      if (n_dir > 0.0) {
        bool shadow = light->is_shadow(sr.world->objects_p, std::make_shared<Shader>(sr));
        if (!shadow) {
          Vector3 h = (sr.ray_casted.direction*-1 + light->get_direction(sr.hit_point)).get_unit_vector();
          L += diff_coef * light->intensity * n_dir;       // diffuse
          L += spec_coef * light->intensity * pow(sr.normal*h, spec_exp); // specular
        }
      }
    }
  }

  RGB final_color = sr.color*L + reflec_color*0.2;
  final_color.norm();
  return final_color;
}

#endif // MIRROR_CPP