#ifndef VIEWPLANE_CPP
#define VIEWPLANE_CPP

#include "utils/RGB.cpp"
#include "CImg/CImg.h"
using namespace cimg_library;

class ViewPlane {
private:
  CImg<unsigned char> img;
  CImgDisplay display;

public:
  unsigned int height;
  unsigned int width;
  float px_size;

  ViewPlane(){};
  ViewPlane(unsigned int _width, unsigned int _height, float _px_size);
  ~ViewPlane(){};

  void paint_px(int x, int y, RGB color);
  void show();
  void wait_display();
};

inline ViewPlane::ViewPlane(unsigned int _width, unsigned int _height, float _px_size)
: width(_width), height(_height), px_size(_px_size) {
  img.assign(width, height, 1, 3, 0); // w h depth channels black
}

inline void ViewPlane::paint_px(int x, int y, RGB color) {
  // the coordinate system in CImg is upside down
  img(width-x-1, height-y-1, 0, 0) = color.r;
  img(width-x-1, height-y-1, 0, 1) = color.g;
  img(width-x-1, height-y-1, 0, 2) = color.b;
}

inline void ViewPlane::show() {
  img.display(display); 
}

inline void ViewPlane::wait_display() {
  while (!display.is_closed()) display.wait();
}

#endif // VIEWPLANE_CPP