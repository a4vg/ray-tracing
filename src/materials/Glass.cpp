#ifndef GLASS_CPP
#define GLASS_CPP

#include "materials/Glass.h"
#include "World.h"

#include <cmath>
#include <iostream>

RGB Glass::shade(Shader &sr) {
  /**
   * https://www.cs.cornell.edu/courses/cs4620/2012fa/lectures/35raytracing.pdf (pg. 10)
   * 
   * Cast a ray from the hit point in inverted direction
   * and add the color to the final results.
   **/
  float eta = 1.25;

  Ray reflec_ray(sr.hit_point+ sr.normal*1e-3, reflected_dir(sr.ray_casted.direction, sr.normal));
  RGB reflec_color = sr.world->hit(reflec_ray, sr.depth+1);
  bool exists = false;
  // Vector3 bias = sr.normal*1e-3;
  // if (exists) bias = bias*-1;
  Vector3 refrac_dir = refracted_dir(exists, sr.ray_casted.direction, sr.normal, eta).get_unit_vector();
  Ray refr_ray(sr.hit_point + refrac_dir*1e-2, refrac_dir);
  // + sr.normal*1e-3
  RGB refracted_color(0,0,0);
  // if (exists){
    refracted_color = sr.world->hit(refr_ray, sr.depth+1);
  // }
  // RGB temp = sr.world->hit(refr_ray, sr.depth+1);

  // std::cout << temp.r << " " << temp.g << " " << temp.b << " " << sr.depth << "\n";

  float diff_coef = .9;
  float spec_coef = .5;
  float spec_exp = 70;
  float L = diff_coef * sr.world->ambient_light.intensity;

  RGB final_color;

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

  final_color =  sr.color*L*0.2 +refracted_color*.5 + reflec_color*0.5;
  final_color.norm();
  return final_color;
}

#endif // GLASS_CPP