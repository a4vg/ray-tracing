#ifndef SHADER_CPP
#define SHADER_CPP

#include <memory>
#include <iostream>

#include "utils/Shader.h"

Shader::Shader(AmbientLight _ambient_light, std::vector<std::shared_ptr<Light>> _lights)
: ambient_light(_ambient_light), lights(_lights) {}

RGB Shader::shade() {
  /**
   * https://www.cs.cornell.edu/courses/cs4620/2017sp/slides/05rt-shading.pdf (pg. 6)
   * 
   * L = k_d * (I/r^2) * max(0, n*l)   <-- k_d diffuse coefficient, I light intensity,
   *                                       r distance of light origin to hit point,
   *                                       n normal of object at hit point, l light direction
   **/

  float diff_coef = 1;
  float L = diff_coef * ambient_light.intensity;

  for (auto light : lights) {
    float n_dir = normal*light->get_direction(hit_point);
    // std::cout << "Color: " << color.r << " " << color.g << " " << color.b << "\n";
    // if (color.r>0 || color.g>0 || color.b>0){
    //   std::cout << "Normal: " << normal.x << " " << normal.y << " " << normal.z << "\n";
    //   std::cout << "Light direction: " << light->get_direction().x << " " << light->get_direction().y << " " << light->get_direction().z << "\n";
    //   std::cout << "n_dir: " << n_dir << "\n";
    // }
    if (n_dir > 0.0)
      L += diff_coef * light->intensity * n_dir;
  }

  RGB final_color = color*L;
  final_color.norm();
  return final_color;
}

#endif // SHADER_CPP