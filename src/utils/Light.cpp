#ifndef LIGHT_CPP
#define LIGHT_CPP

#include "Point3.cpp"
#include "RGB.cpp"

struct Light
{
  Point3 origin;
  RGB color;
};

#endif // LIGHT_CPP