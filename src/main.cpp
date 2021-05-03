#ifndef MAIN_CPP
#define MAIN_CPP

#include <memory>

#include "World.cpp"
#include "ViewPlane.cpp"
#include "utils/RGB.cpp"
#include "utils/Point3.cpp"
#include "geometry/Sphere.cpp"

void build(World &w, ViewPlane &vp) {
  vp = ViewPlane(200, 200, 1); // w h pxs
  RGB blue(0,0,250);
  w.add_object(std::make_shared<Sphere>(blue, Point3(0,0,0), 85));
}

void render(World &w, ViewPlane &vp, float depth) {
  float x, y;
  Ray ray;
  RGB px_color;

  ray.direction = Vector3(0,0,-1);

  for (int r=0; r<vp.height; ++r) {
    for (int c=0; c<vp.width; ++c) {
      x = vp.px_size * (c- 0.5 * (vp.width-1));
      y = vp.px_size * (r- 0.5 * (vp.height-1));
      ray.origin = Point3(x, y, depth);
      px_color = w.hit(ray);

      vp.paint_px(r, c, px_color);
    }
    vp.show();
  }
  vp.wait_display();
}
 
int main() {
  World w;
  ViewPlane vp;
  build(w, vp);
  render(w, vp, 100);
  return 0;
}

#endif // MAIN_CPP