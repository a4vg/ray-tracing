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
#include "light/PointLight.h"
#include "light/DirectionalLight.h"

void build(World &w, ViewPlane &vp) {
  vp = ViewPlane(400, 400, 1); // w h pxs
  w.set_ambient_light(AmbientLight(RGB(250,250,250), Vector3(0,0,1), 0.4));
  w.add_light(std::make_shared<PointLight>(RGB(250,250,250), Point3(0,-1,0), 1.3));
  w.add_light(std::make_shared<DirectionalLight>(RGB(250,250,250), Vector3(0,0,1), 0.3));

  RGB blue(0,0,255);
  RGB red(255,0,0);
  RGB green(0,255,0);
  w.add_object(std::make_shared<Cylinder>(green, Point3(0,40,-80), 50, -50, 40));
  w.add_object(std::make_shared<Sphere>(red, Point3(100,100,0), 40));
  w.add_object(std::make_shared<Plane>(blue, Vector3(0,1,-0.3), Point3(0,0, 200)));
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
