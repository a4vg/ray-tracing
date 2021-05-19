#ifndef MATTE_CPP
#define MATTE_CPP

#include "materials/Matte.h"
#include "World.h"

RGB Matte::shade(Shader &sr) {
  /**
   * https://www.cs.cornell.edu/courses/cs4620/2017sp/slides/05rt-shading.pdf (pg. 6)
   * 
   * Matte shading = only diffuse
   * 
   * L_diffuse = k_d * I * max(0, n*l)   <-- k_d diffuse coefficient, I light intensity,
   *                                               n normal of object at hit point, l light direction
   **/

  float diff_coef = 1;
  float L = diff_coef * sr.world->ambient_light.intensity;

  if (sr.obj_p) { // check if ray hit something
    for (auto light : sr.world->lights) {
      float n_dir = sr.normal*light->get_direction(sr.hit_point);

      if (n_dir > 0.0) {
        bool shadow = light->is_shadow(sr.world->objects_p, std::make_shared<Shader>(sr));
        if (!shadow)
          L += diff_coef * light->intensity * n_dir / (pow(light->distance(sr.hit_point), 2));
      }
    }
  }

  RGB final_color = sr.color*L;
  final_color.norm();
  return final_color;
}

#endif // MATTE_CPP