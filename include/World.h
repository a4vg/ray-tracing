#ifndef WORLD_H
#define WORLD_H

#include <vector>
#include <memory>

#include "geometry/Object.h" // Shader
#include "light/AmbientLight.h"
#include "light/Light.h"
#include "ViewPlane.h"

class World {
private:
  RGB bg_color = RGB(0,0,0);
  ViewPlane vp;

  void add_firefly(Point3 coords);
public:
  std::vector<std::shared_ptr<Object>> objects_p;
  AmbientLight ambient_light;
  std::vector<std::shared_ptr<Light>> lights;
  int max_depth = 10;

  World() {};
  ~World() {};

  void add_object(std::shared_ptr<Object> obj_p) { objects_p.push_back(obj_p); };
  void add_light(std::shared_ptr<Light> _light) { lights.push_back(_light); };
  void set_ambient_light(AmbientLight _ambient_light) { ambient_light = _ambient_light; };
  RGB hit(Ray &ray, int depth=1);

  void build_static();
  void render();
  void make_video();
};

#endif // WORLD_H