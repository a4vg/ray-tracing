#ifndef MAIN_CPP
#define MAIN_CPP

#include <memory>

#include "World.h"
#include "ViewPlane.h"
#include "utils/RGB.h"
#include "utils/Point3.h"
#include "utils/Shader.h"
#include "geometry/Sphere.h"
#include "geometry/Plane.h"
#include "geometry/Cylinder.h"
#include "geometry/Box.h"

void build(World &w, ViewPlane &vp) {
  vp = ViewPlane(200, 200, 1); // w h pxs
  w.set_light(DirectionalLight(RGB(250,250,250), Vector3(0,0,1), 1));
  RGB blue(0,0,255);
  RGB red(255,0,0);
  RGB green(0,255,0);
  // w.add_object(std::make_shared<Sphere>(blue, Point3(0,-25,0), 80));
  w.add_object(std::make_shared<Sphere>(red, Point3(0,30,0), 60 )); // test
  // w.add_object(std::make_shared<Plane>(green, Vector3(0,1,1), Point3(0,0,0))); // test
  w.add_object(std::make_shared<Cylinder>(green, Point3(0,50,0), 20, -20, 40)); // teat
  // w.add_object(std::make_shared<Sphere>(red, Point3(0,0,0), 20));
  // w.add_object(std::make_shared<Sphere>(blue, Point3(0,100,0), 20));
  // w.add_object(std::make_shared<Box>(green, Point3(0,0,0), Point3(50,50,50)));
}

void render(World &w, ViewPlane &vp, float depth) {
  float x, y;
  Ray ray;
  RGB px_color;

  ray.direction = Vector3(0,.7,-1);

  for (int r=0; r<vp.height; ++r) {
    for (int c=0; c<vp.width; ++c) {
      x = vp.px_size * (c- 0.5 * (vp.width-1));
      y = vp.px_size * (r- 0.5 * (vp.height-1));
      ray.origin = Point3(x, y, depth);
      px_color = w.hit(ray);

      vp.paint_px(c, r, px_color);
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