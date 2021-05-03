#ifndef RGB_CPP
#define RGB_CPP

struct RGB {
  int r, g, b;

  RGB(){};
  RGB(int _r, int _g, int _b)
  : r(_r), g(_g), b(_b) {};

  // Copy
  RGB(const RGB& rgb): r(rgb.r), g(rgb.b), b(rgb.b) {};
  // RGB& operator=(RGB rgb) { r=rgb.r; g=rgb.g; b=rgb.b; return *this; }
};

#endif // RGB_CPP