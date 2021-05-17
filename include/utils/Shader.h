#ifndef SHADER_H
#define SHADER_H

#include <memory>
#include <vector>

// #include "../World.h"

class World;
class Object;

#include "../utils/Ray.h" // Point3 -> Vector3
#include "../light/AmbientLight.h"
#include "../light/Light.h"

class Shader {
public:
  std::shared_ptr<World> world;
  Ray ray_casted;
  Point3 hit_point;
  Vector3 normal;
  RGB color;
  std::shared_ptr<Object> obj_p = nullptr;

  Shader() {};
  Shader(std::shared_ptr<World> world);
  ~Shader(){};

  void operator=(const Shader &sr); // copy
};

#endif // SHADER_H