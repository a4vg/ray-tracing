#ifndef AMBIENTLIGHT_H
#define AMBIENTLIGHT_H

#include "../utils/RGB.h"
#include "Light.h" // Vector3

class AmbientLight: public Light {
public:
  AmbientLight() {};
  AmbientLight(RGB _color, float _intensity);
  ~AmbientLight() {};

  Vector3 get_direction(Point3 &hit_point) { return Vector3(0,0,0); };
  bool is_shadow(std::vector<std::shared_ptr<Object>> objects_p, std::shared_ptr<Shader> sr) { return false; };
  float distance(Point3 &p) { return 1; }
};

#endif // AMBIENTLIGHT_H