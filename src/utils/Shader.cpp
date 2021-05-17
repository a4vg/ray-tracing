#ifndef SHADER_CPP
#define SHADER_CPP

#include <memory>
#include <iostream>

#include "utils/Shader.h"

Shader::Shader(std::shared_ptr<World> _world)
: world(_world) {}

void Shader::operator=(const Shader &sr) { 
  ray_casted = sr.ray_casted;
  hit_point = sr.hit_point;
  normal = sr.normal;
  color = sr.color;
  obj_p = sr.obj_p;
}

#endif // SHADER_CPP