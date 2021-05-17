#ifndef MATTE_H
#define MATTE_H

#include "utils/Shader.h"
#include "materials/Material.h"

// Matte only has diffuse reflection

class Matte : public Material {
public:
  Matte(){};
  ~Matte(){};

  RGB shade(Shader &sr);
};

#endif // MATTE_H