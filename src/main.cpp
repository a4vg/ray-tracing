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

void add_firefly(World &w, Point3 coords) {
  w.add_object(std::make_shared<Sphere>(colors::yellow, mats_p::mirror, coords, 5));
  coords.y = coords.y+6;
  coords.z = coords.z+10;
  auto point_light_p = std::make_shared<PointLight>(RGB(255,255,255), coords, 10);
  // point_light_p->no_shadow = true;
  w.add_light(point_light_p);
}

void build(World &w, ViewPlane &vp) {
  vp = ViewPlane(400, 400, 1); // w h pxs
  w.max_depth = 4;

  w.set_ambient_light(AmbientLight(RGB(255,255,255), 0.2));
  w.add_light(std::make_shared<DirectionalLight>(RGB(255,255,255), Vector3(-.5,-1,-1), 0.4));

  // w.add_light(std::make_shared<PointLight>(RGB(255,255,255), Point3(-200,100,100), .5));
  // w.add_object(std::make_shared<Sphere>(colors::yellow, mats_p::phong, Point3(-90,-20,300), 10));

  // w.add_object(std::make_shared<Sphere>(colors::pink, mats_p::phong, Point3(-40,0,20), 50));
  w.add_object(std::make_shared<Cylinder>(colors::white, mats_p::glass, Point3(0,0,150), -50, 50, 50));
  w.add_object(std::make_shared<Plane>(colors::white, mats_p::matte, Vector3(0,1,0), Point3(0,-50, 5)));
  add_firefly(w, Point3(0,0,150));
  add_firefly(w, Point3(-10,20,150));

  // w.add_object(std::make_shared<Sphere>(colors::yellow, mats_p::matte, Point3(40,0,200), 5));
  // w.add_light(std::make_shared<PointLight>(RGB(255,255,255), Point3(40,0,210), 2));

}

void render(World &w, ViewPlane &vp) {
  Camera(
    Point3(0,100,500), // eye
    Point3(0,0,100), // lookat
    vp,
    500
    , 1.5
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
