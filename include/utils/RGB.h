#ifndef RGB_H
#define RGB_H

#include <algorithm>

struct RGB {
  int r, g, b;

  RGB(){};
  RGB(int _r, int _g, int _b)
  : r(_r), g(_g), b(_b) {};

  // Copy
  RGB(const RGB& rgb): r(rgb.r), g(rgb.g), b(rgb.b) {};
  void operator=(RGB rgb) { r=rgb.r; g=rgb.g; b=rgb.b; }

  RGB operator*(float s) const { return RGB(r*s, g*s, b*s); };
  RGB operator+(RGB &rgb) const { return RGB(r+rgb.r, g+rgb.g, b+rgb.b); };

  void norm() { // max to one technique
    int m = std::max(r, std::max(g, b));
    if (m > 255) r=r/m*255, g=g/m*255, b=b/m*255;
  };
};

#endif // RGB_H