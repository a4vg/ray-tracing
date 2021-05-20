#ifndef VIEWPLANE_CPP
#define VIEWPLANE_CPP

#include <iostream>

#include "ViewPlane.h"

ViewPlane::ViewPlane(ViewPlane &vp)
: width(vp.width), height(vp.height), px_size(vp.px_size) {
  img.assign(width, height, 1, 3, 0); // w h depth channels black
}

ViewPlane::ViewPlane(unsigned int _width, unsigned int _height, float _px_size)
: width(_width), height(_height), px_size(_px_size) {
  img.assign(width, height, 1, 3, 0); // w h depth channels black
}

void ViewPlane::paint_px(int x, int y, RGB color) {
  // the coordinate system in CImg is upside down
  img(x, height-y-1, 0, 0) = color.r;
  img(x, height-y-1, 0, 1) = color.g;
  img(x, height-y-1, 0, 2) = color.b;
}

void ViewPlane::show() {
  img.display(display); 
}

void ViewPlane::wait_display() {
  while (!display.is_closed()) display.wait();
}

void ViewPlane::print_frame() {
  char* s=reinterpret_cast<char*>(img.data()+(width*height));
  std::cout.write(s,width*height);
  s=reinterpret_cast<char*>(img.data()+2*(width*height));
  std::cout.write(s,width*height);
  s=reinterpret_cast<char*>(img.data());
  std::cout.write(s,width*height);   
}

void ViewPlane::write_to(std::string filename) {
  img.save(filename.c_str());
}

#endif // VIEWPLANE_CPP