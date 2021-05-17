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
private:
  std::shared_ptr<World> world;
public:
  Ray ray;
  Point3 hit_point;
  Vector3 normal;
  RGB color;
  std::shared_ptr<Object> obj_p = nullptr;

  Shader() {};
  Shader(std::shared_ptr<World> world);
  ~Shader(){};

  void operator=(const Shader &sr); // copy
  RGB shade();
};

#endif // SHADER_H