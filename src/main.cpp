#ifndef MAIN_CPP
#define MAIN_CPP

#include <memory>

#include "World.h"
#include "ViewPlane.h"
#include "Camera.h"
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
  vp = ViewPlane(300, 300, 1); // w h pxs
  w.set_ambient_light(AmbientLight(RGB(255,255,255), 0.5));
  w.add_light(std::make_shared<DirectionalLight>(RGB(255,255,255), Vector3(1,0,-1), 0.4));

  // w.add_light(std::make_shared<PointLight>(RGB(255,255,255), Point3(0,0,50), 1));

  RGB blue(0,0,255);
  RGB red(255,0,0);
  RGB green(0,255,0);
  RGB yellow(255,255,0);
  // w.add_object(std::make_shared<Sphere>(yellow, Point3(130,0,10), 20));

  w.add_object(std::make_shared<Cylinder>(green, Point3(130,0,10), 50, -50, 40));
  // w.add_object(std::make_shared<Sphere>(red, Point3(100,100,0), 40));
  // w.add_object(std::make_shared<Plane>(blue, Vector3(0,1,-0.3), Point3(0,0, 200)));
}

void render(World &w, ViewPlane &vp) {
  Camera(
    Point3(0,0,500), // eye
    Point3(0,0,0),   // lookat
    vp,
    500
  ).render(w);
}
 
int main() {
  World w;
  ViewPlane vp;
  build(w, vp);
  render(w, vp);
  return 0;
}

#endif // MAIN_CPP
