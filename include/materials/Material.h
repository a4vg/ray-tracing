#ifndef MATERIAL_H
#define MATERIAL_H

#include "utils/Shader.h"

class Material {
public:
  Material(){};
  ~Material(){};

  virtual RGB shade(Shader &sr) = 0;
};

#endif // MATERIAL_H