#ifndef SHADER_CPP
#define SHADER_CPP

#include <memory>
#include <iostream>

#include "utils/Shader.h"
#include "World.h"

Shader::Shader(std::shared_ptr<World> _world)
: world(_world) {}

void Shader::operator=(const Shader &sr) { 
  ray = sr.ray;
  hit_point = sr.hit_point;
  normal = sr.normal;
  color = sr.color;
  obj_p = sr.obj_p;
}

RGB Shader::shade() {
  /**
   * https://www.cs.cornell.edu/courses/cs4620/2017sp/slides/05rt-shading.pdf (pg. 6)
   * 
   * L = k_d * (I/r^2) * max(0, n*l)   <-- k_d diffuse coefficient, I light intensity,
   *                                       r distance of light origin to hit point,
   *                                       n normal of object at hit point, l light direction
   **/

  float diff_coef = 1;
  float L = diff_coef * world->ambient_light.intensity;

  if (obj_p) { // check if ray hit something
    for (auto light : world->lights) {
      float n_dir = normal*light->get_direction(hit_point);


      if (n_dir > 0.0) {
        bool shadow = light->is_shadow(world->objects_p, std::make_shared<Shader>(*this));
        if (!shadow)
          L += diff_coef * light->intensity * n_dir;
      }
    }
  }

  RGB final_color = color*L;
  final_color.norm();
  return final_color;
}

#endif // SHADER_CPP