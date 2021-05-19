#ifndef MATERIAL_H
#define MATERIAL_H

#include "utils/Shader.h"

class Material {
public:
  Material(){};
  ~Material(){};

  virtual RGB shade(Shader &sr) = 0;
  static Vector3 reflected_dir(Vector3 &ray_dir, Vector3 &normal);
  static Vector3 refracted_dir(bool& exists, Vector3 ray_dir, Vector3 normal, float eta_mat, float eta_env=1);
};

#endif // MATERIAL_H