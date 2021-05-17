#ifndef MAIN_CPP
#define MAIN_CPP

#include <memory>

#include "World.h"
#include "ViewPlane.h"
#include "Camera.h"
#include "utils/Point3.h"
#include "utils/Shader.h"
#include "geometry/Sphere.h"
#include "geometry/Plane.h"
#include "geometry/Cylinder.h"
#include "geometry/Box.h"
#include "light/PointLight.h"
#include "light/DirectionalLight.h"
#include "collections/Colors.cpp"
#include "collections/MatsP.cpp"

void build(World &w, ViewPlane &vp) {
  vp = ViewPlane(400, 400, 1); // w h pxs
  w.set_ambient_light(AmbientLight(RGB(255,255,255), 0.2));
  w.add_light(std::make_shared<DirectionalLight>(RGB(255,255,255), Vector3(-.5,-1,-.5), 0.5));

  w.add_light(std::make_shared<PointLight>(RGB(255,255,255), Point3(-90,-20,300), .5));
  // w.add_object(std::make_shared<Sphere>(colors::yellow, mats_p::phong, Point3(-90,-20,300), 10));

  w.add_object(std::make_shared<Sphere>(colors::green, mats_p::phong, Point3(-60,0,20), 50));
  w.add_object(std::make_shared<Sphere>(colors::red, mats_p::matte, Point3(60,0,20), 50));
  // w.add_object(std::make_shared<Cylinder>(colors::blue, mats_p::phong, Point3(0,0, 150), 0, 60, 40));
  w.add_object(std::make_shared<Plane>(colors::white, mats_p::mirror, Vector3(0,1,0), Point3(0,-50, 5)));
}

void render(World &w, ViewPlane &vp) {
  Camera(
    Point3(0,100,500), // eye
    Point3(0,0,100), // lookat
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
