#ifndef SHADER_H
#define SHADER_H

#include <memory>

// #include "../World.h"

// class World;
#include "../utils/Ray.h" // Point3 -> Vector3
#include "../light/DirectionalLight.h"

class Shader {
private:
  std::shared_ptr<DirectionalLight> light;
public:
  Ray ray;
  Point3 hit_point;
  Vector3 normal;
  RGB color;

  Shader() {};
  Shader(std::shared_ptr<DirectionalLight> _light);
  ~Shader(){};

  RGB shade();
};

#endif // SHADER_H