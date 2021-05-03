#ifndef WORLD_CPP
#define WORLD_CPP

#include <vector>
#include <memory>

#include "geometry/Object.cpp"

class World {
private:
  std::vector<std::shared_ptr<Object>> objects_p;
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
  for (auto obj_p: objects_p) {
    if (obj_p->intersection(ray)) return obj_p->color;
  }
  return RGB(0,0,0);
}

#endif // WORLD_CPP