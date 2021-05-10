#ifndef WORLD_H
#define WORLD_H

#include <vector>
#include <memory>

#include "geometry/Object.h" // Shader
#include "light/DirectionalLight.h"

class World {
private:
  std::vector<std::shared_ptr<Object>> objects_p;
  RGB bg_color = RGB(0,0,0);
public:
  DirectionalLight light;

  World() {};
  World(std::vector<std::shared_ptr<Object>> _objects, DirectionalLight &_light);
  ~World() {};

  void add_object(std::shared_ptr<Object> obj_p) { objects_p.push_back(obj_p); };
  void set_light(DirectionalLight _light) { light = _light; };
  RGB hit(Ray &ray);
};

#endif // WORLD_H