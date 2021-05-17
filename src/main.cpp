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
  w.set_ambient_light(AmbientLight(RGB(255,255,255), 0.2));
  w.add_light(std::make_shared<DirectionalLight>(RGB(255,255,255), Vector3(0,-1,-.5), 0.4));

  w.add_light(std::make_shared<PointLight>(RGB(255,255,255), Point3(-40,40,50), 0.5));

  RGB blue(0,0,255);
  RGB red(255,0,0);
  RGB green(0,255,0);
  RGB yellow(255,255,0);
  RGB white(255,255,255);
  w.add_object(std::make_shared<Sphere>(red, Point3(60,0,20), 20));
  w.add_object(std::make_shared<Sphere>(green, Point3(6,0,20), 30));
  // w.add_object(std::make_shared<Sphere>(blue, Point3(-40,30,50), 10));
  w.add_object(std::make_shared<Cylinder>(red, Point3(-70,0,20), 50, -40, 30));
  w.add_object(std::make_shared<Plane>(white, Vector3(0,1,0), Point3(0,-50, 5)));
}

void render(World &w, ViewPlane &vp) {
  Camera(
    Point3(0,0,500), // eye
    Point3(0,0,100), // lookat
    vp,
    500,
    1.0
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
