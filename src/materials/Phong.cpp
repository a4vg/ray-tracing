#ifndef PHONG_CPP
#define PHONG_CPP

#include "materials/Phong.h"
#include "World.h"

#include <cmath>

RGB Phong::shade(Shader &sr) {
  /**
   * https://www.cs.cornell.edu/courses/cs4620/2012fa/lectures/35raytracing.pdf (pg. 8)
   * 
   * Phong shading = diffuse + specular
   * 
   * L_specular = k_s * I * max(0, n*h)   <-- k_s specular coefficient, I light intensity,
   *                                          r distance of light origin to hit point,
   *                                          n normal of object at hit point
   * h = bisector of v and l              <-- v eye direction (ray casted inverted), l light direction
   * h = (v+l)/ (v+l).length
   * 
   * Bonus: By elevating n*h to the specular exponent, the specular
   * light with be smaller (Ray Tracing from the Ground Up, Fig. 15.7, pg. 285)
   **/

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

  RGB final_color = sr.color*L;
  final_color.norm();
  return final_color;
}


#endif // PHONG_CPP