#ifndef WORLD_CPP
#define WORLD_CPP

#include <limits>

#include "World.h"

const float INF = std::numeric_limits<float>::max();

RGB World::hit(Ray &ray) {
  Shader sr(ambient_light, lights);

  float t, t_min=INF;
  RGB color = bg_color;
  for (auto obj_p: objects_p) {
    if (obj_p->intersection(ray, t, sr)) {
      if (t<t_min) {
        t_min = t;
        color = obj_p->color;
      }
    }
  }

  sr.color = color;
  return sr.shade();
  // return color;
}

#endif // WORLD_CPP