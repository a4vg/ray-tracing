#ifndef SHADER_H
#define SHADER_H

#include <memory>
#include <vector>

// #include "../World.h"

// class World;
#include "../utils/Ray.h" // Point3 -> Vector3
#include "../light/AmbientLight.h"
#include "../light/Light.h"

class Shader {
private:
  AmbientLight ambient_light;
  std::vector<std::shared_ptr<Light>> lights;
public:
  Ray ray;
  Point3 hit_point;
  Vector3 normal;
  RGB color;

  Shader() {};
  Shader(AmbientLight _ambient_light, std::vector<std::shared_ptr<Light>> _lights);
  ~Shader(){};

  RGB shade();
};

#endif // SHADER_H