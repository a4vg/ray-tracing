#ifndef LIGHT_H
#define LIGHT_H

#include "../utils/Vector3.h"

class Light {
public:
  Light(){};
  virtual ~Light(){};

  virtual Vector3 get_direction() = 0;
};

#endif // LIGHT_H