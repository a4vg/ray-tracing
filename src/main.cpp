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
  vp = ViewPlane(300, 300, 1); // w h pxs
  w.set_ambient_light(AmbientLight(RGB(255,255,255), 0.3));
  w.add_light(std::make_shared<DirectionalLight>(RGB(255,255,255), Vector3(-.5,-1,-.5), 0.7));

  w.add_light(std::make_shared<PointLight>(RGB(255,255,255), Point3(-40,40,120), .8));
  w.add_object(std::make_shared<Sphere>(colors::yellow, mats_p::matte, Point3(-40,40,160), 10));

  w.add_object(std::make_shared<Sphere>(colors::red, mats_p::matte, Point3(60,0,20), 20));
  w.add_object(std::make_shared<Sphere>(colors::green, mats_p::matte, Point3(6,0,20), 30));
  w.add_object(std::make_shared<Cylinder>(colors::red, mats_p::matte, Point3(-70,0,10), 60, -40, 20)); // color center start end radius
  w.add_object(std::make_shared<Plane>(colors::white, mats_p::matte, Vector3(0,1,0), Point3(0,-50, 5)));
}

void render(World &w, ViewPlane &vp) {
  Camera(
    Point3(0,50,500), // eye
    Point3(-50,0,100), // lookat
    vp,
    500
    // , 4.0
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
