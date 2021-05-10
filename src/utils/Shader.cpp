#ifndef SHADER_CPP
#define SHADER_CPP

#include <memory>
#include <iostream>

#include "utils/Shader.h"

Shader::Shader(std::shared_ptr<DirectionalLight> _light) : light(_light) {}

RGB Shader::shade() {
  /**
   * https://www.cs.cornell.edu/courses/cs4620/2017sp/slides/05rt-shading.pdf (pg. 6)
   * 
   * L = k_d * (I/r^2) * max(0, n*l)   <-- k_d diffuse coefficient, I light intensity,
   *                                       r distance of light origin to hit point,
   *                                       n normal of object at hit point, l light direction
   **/

  float L = 0;
  float diff_coef = 1;
  float n_dir = normal*light->get_direction();
  // std::cout << "Color: " << color.r << " " << color.g << " " << color.b << "\n";
  if (color.r>0 || color.g>0 || color.b>0){
    // std::cout << "Normal: " << normal.x << " " << normal.y << " " << normal.z << "\n";
    // std::cout << "Light direction: " << light->get_direction().x << " " << light->get_direction().y << " " << light->get_direction().z << "\n";
    // std::cout << "n_dir: " << n_dir << "\n";
  }
  if ((n_dir) > 0.0)
    L = diff_coef * light->intensity * n_dir;

  return color*L;
}

#endif // SHADER_CPP