#ifndef MIRROR_H
#define MIRROR_H

#include "utils/Shader.h"
#include "materials/Material.h"

class Mirror : public Material {
public:
  Mirror(){};
  ~Mirror(){};

  RGB shade(Shader &sr);
};

#endif // MIRROR_H