#ifndef SHADER_CPP
#define SHADER_CPP

#include <memory>
#include <iostream>

#include "utils/Shader.h"
#include "World.h"

Shader::Shader(std::shared_ptr<World> _world)
: world(_world) {}

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

  for (auto light : world->lights) {
    float n_dir = normal*light->get_direction(hit_point);
    // std::cout << "Color: " << color.r << " " << color.g << " " << color.b << "\n";
    // if (color.r>0 || color.g>0 || color.b>0){
    //   std::cout << "Normal: " << normal.x << " " << normal.y << " " << normal.z << "\n";
    //   std::cout << "Light direction: " << light->get_direction().x << " " << light->get_direction().y << " " << light->get_direction().z << "\n";
    //   std::cout << "n_dir: " << n_dir << "\n";
    // }


    
    float current_t = (light->get_origin(hit_point) - hit_point).length();
    float tmp_t = 1e10;
    Ray tmp_r(hit_point, light->get_direction(hit_point));
    bool shadow = false;
    for (auto other_obj_p : world->objects_p) {
      if (obj_p == other_obj_p) continue; // same object
      other_obj_p->intersection(tmp_r, tmp_t);
      if (tmp_t<current_t) {
        shadow = true;
        std::cout << "Shadow!\n";
        break;
      }
    }
    if (!shadow && n_dir > 0.0)
      L += diff_coef * light->intensity * n_dir;
  }

  RGB final_color = color*L;
  final_color.norm();
  return final_color;
}

#endif // SHADER_CPP