#ifndef LIGHT_H
#define LIGHT_H

class Shader;
class Object;

#include <vector>
#include <memory>

#include "../utils/Point3.h" // Vector3

class Light {
public:
  RGB color;
  Vector3 direction;
  float intensity;
  
  Light(){};
  Light(RGB _color, Vector3 _direction, float _intensity)
  : color(_color), direction(_direction), intensity(_intensity) {};
  virtual ~Light(){};

  virtual Vector3 get_direction(Point3 &hit_point) = 0;
  virtual bool is_shadow(std::vector<std::shared_ptr<Object>> objects_p, std::shared_ptr<Shader> sr) = 0;
};

#endif // LIGHT_H