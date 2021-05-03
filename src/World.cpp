#ifndef WORLD_CPP
#define WORLD_CPP

#include <vector>
#include <memory>
#include <limits>

#include "geometry/Object.cpp"

const float INF = std::numeric_limits<float>::max();

class World {
private:
  std::vector<std::shared_ptr<Object>> objects_p;
  RGB bg_color = RGB(0,0,0);
public:
  World() {};
  World(std::vector<std::shared_ptr<Object>> _objects);
  ~World() {};

  void add_object(std::shared_ptr<Object> obj_p);
  RGB hit(Ray &ray);
};

inline World::World(std::vector<std::shared_ptr<Object>> _objects_p)
: objects_p(_objects_p) {}

inline void World::add_object(std::shared_ptr<Object> obj_p) {
  objects_p.push_back(obj_p);
}

inline RGB World::hit(Ray &ray) {
  float t, t_min=INF;
  RGB color = bg_color;
  for (auto obj_p: objects_p) {
    if (obj_p->intersection(ray, t)) {
      if (t<t_min) {
        t_min = t;
        color = obj_p->color;
      }
    }
  }
  return color;
}

#endif // WORLD_CPP