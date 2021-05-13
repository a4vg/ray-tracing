#ifndef VIEWPLANE_H
#define VIEWPLANE_H

#include "utils/RGB.h"
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
  ViewPlane(ViewPlane &vp);
  ViewPlane(unsigned int _width, unsigned int _height, float _px_size);
  ~ViewPlane(){};

  void paint_px(int x, int y, RGB color);
  void show();
  void wait_display();
};

#endif // VIEWPLANE_H