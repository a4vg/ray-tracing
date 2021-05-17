#ifndef PHONG_H
#define PHONG_H

#include "utils/Shader.h"
#include "materials/Material.h"

class Phong : public Material {
public:
  Phong(){};
  ~Phong(){};

  RGB shade(Shader &sr);
};

#endif // PHONG_H