#ifndef WORLD_CPP
#define WORLD_CPP

#include <limits>
#include <iostream>

#include "World.h"

const float INF = std::numeric_limits<float>::max();

RGB World::hit(Ray &ray) {
  auto sr = std::make_shared<Shader>(std::make_shared<World>(*this));

  float t, t_min=INF;
  RGB color = bg_color;
  int c=0;
  int ind = 0;
  for (auto obj_p: objects_p) {
    ++c;
    if (obj_p->intersection(ray, t, sr)) {
      if (t<t_min) {
        t_min = t;
        color = obj_p->color;
        sr->obj_p = obj_p;
        ind = c;
      }
    }
  }

  // std::cout << "object: " << ind << "\n";
  sr->color = color;
  return sr->shade();
  // return color;
}

#endif // WORLD_CPP