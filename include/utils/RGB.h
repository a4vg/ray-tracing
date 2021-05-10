#ifndef RGB_H
#define RGB_H

struct RGB {
  int r, g, b;

  RGB(){};
  RGB(int _r, int _g, int _b)
  : r(_r), g(_g), b(_b) {};

  // Copy
  RGB(const RGB& rgb): r(rgb.r), g(rgb.g), b(rgb.b) {};
  RGB& operator=(RGB rgb) { r=rgb.r; g=rgb.g; b=rgb.b; return *this; }

  RGB operator*(float s) const { return RGB(r*s, g*s, b*s); };
};

#endif // RGB_H