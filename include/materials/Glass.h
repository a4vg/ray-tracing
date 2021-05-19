#ifndef GLASS_H
#define GLASS_H

#include "utils/Shader.h"
#include "materials/Material.h"

class Glass : public Material {
public:
  Glass(){};
  ~Glass(){};

  RGB shade(Shader &sr);
};

#endif // GLASS_H