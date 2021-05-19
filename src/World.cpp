#ifndef WORLD_CPP
#define WORLD_CPP

#include <limits>
#include <iostream>

#include "World.h"

const float INF = std::numeric_limits<float>::max();

RGB World::hit(Ray &ray, int depth) {
  if (depth > max_depth) return RGB(0,0,0);

  auto sr = std::make_shared<Shader>(std::make_shared<World>(*this));
  auto f_sr = Shader(std::make_shared<World>(*this));

  f_sr.depth = depth;

  float t, t_min=INF;
  f_sr.color = bg_color;
  for (auto obj_p: objects_p) {
    if (obj_p->intersection(ray, t, sr)) {
      if (t<t_min) {
        f_sr = *sr;
        t_min = t;
        f_sr.obj_p = obj_p;
      }
    }
  }
  
  f_sr.ray_casted = ray;
  return f_sr.obj_p? f_sr.obj_p->shade(f_sr) : bg_color;
}

#endif // WORLD_CPP