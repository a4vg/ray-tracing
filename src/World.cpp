#ifndef WORLD_CPP
#define WORLD_CPP

#include <limits>
#include <iostream>

#include "World.h"

const float INF = std::numeric_limits<float>::max();

RGB World::hit(Ray &ray) {
  auto sr = std::make_shared<Shader>(std::make_shared<World>(*this));
  auto f_sr = Shader(std::make_shared<World>(*this));

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

  return f_sr.shade();
}

#endif // WORLD_CPP