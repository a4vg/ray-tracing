#ifndef WORLD_CPP
#define WORLD_CPP

#include <limits>
#include <iostream>
#include <ctime>
#include <cstdlib>

#include "World.h"
#include "Camera.h"
#include "collections/Colors.cpp"
#include "collections/MatsP.cpp"
#include "geometry/Sphere.h"
#include "geometry/Plane.h"
#include "geometry/Cylinder.h"
#include "light/PointLight.h"
#include "light/DirectionalLight.h"
#include "utils/Point3.h"

const float INF = std::numeric_limits<float>::max();

RGB World::hit(Ray &ray, int depth) {
  if (depth > max_depth) return RGB(0,0,0);

  auto sr = std::make_shared<Shader>(std::make_shared<World>(*this));
  auto f_sr = Shader(std::make_shared<World>(*this));

  f_sr.depth = depth;

  float t, t_min=INF;
  f_sr.color = bg_color;
  for (auto obj_p: objects_p) {
    if (obj_p->intersection(ray, t, sr)) {
      if (t<t_min) {
        f_sr = *sr;
        t_min = t;
        f_sr.obj_p = obj_p;
      }
    }
  }
  
  f_sr.ray_casted = ray;
  return f_sr.obj_p? f_sr.obj_p->shade(f_sr) : bg_color;
}

void World::add_firefly(Point3 coords) {
  add_object(std::make_shared<Sphere>(colors::yellow, mats_p::mirror, coords, 3));
  coords.y = coords.y+5;
  coords.z = coords.z+8;
  auto point_light_p = std::make_shared<PointLight>(RGB(255,255,255), coords, 6);
  // point_light_p->no_shadow = true;
  add_light(point_light_p);
}

void World::build_static() {
  vp = ViewPlane(400, 400, 1); // w h pxs
  max_depth = 4;

  set_ambient_light(AmbientLight(RGB(255,255,255), 0.2));
  add_light(std::make_shared<DirectionalLight>(RGB(255,255,255), Vector3(-.5,-1,-1), 0.3));

  add_object(std::make_shared<Cylinder>(colors::white, mats_p::glass, Point3(0,0,150), 0, 100, 50));
  add_object(std::make_shared<Plane>(colors::white, mats_p::matte, Vector3(0,1,0), Point3(0,0, 5)));
  add_firefly(Point3(0,30,150));
  add_firefly(Point3(-10,70,130));
  add_firefly(Point3(30,90,170));
  add_firefly(Point3(20,60,160));
}

void World::render() {
  Camera(
    Point3(0,150,500), // eye
    Point3(0,50,100), // lookat
    vp,
    500
  ).write_image(*this, "test.bmp");
}

void World::make_video() {
  srand(time(NULL));

  vp = ViewPlane(400, 400, 1);
  max_depth = 4;

  // Static lights
  set_ambient_light(AmbientLight(RGB(255,255,255), 0.2));
  add_light(std::make_shared<DirectionalLight>(RGB(255,255,255), Vector3(-.5,-1,-1), 0.3));


  const int time = 3;
  const int fps = 24;
  Point3 op[4] = {Point3(0,30,150), Point3(-10,70,130), Point3(30,90,170), Point3(20,60,160)};

  for (int i=0; i<time*fps; ++i) {
    Camera cam(
      Point3(0+i*2,150+i*2,500-i*2), // eye
      Point3(0,50,100), // lookat
      vp,
      500
    );
    add_object(std::make_shared<Cylinder>(colors::white, mats_p::glass, Point3(0,0,150), 0, 120, 60));
    add_object(std::make_shared<Plane>(colors::white, mats_p::matte, Vector3(0,1,0), Point3(0,0, 5)));

    for (int p=0; p<4; ++p) {
      int r1 = rand()%7 -3; // [-3, 3]
      int r2 = rand()%7 -3;
      op[p].x = op[p].x + r1;
      op[p].y = op[p].y + r2;
      if (!r1 && !r2) {
        if (rand()%2) ++op[p].x;
        else ++op[p].y;
      }
      add_firefly(op[p]);
    }

    // Output to ffmpeg to make video, in planar GBR format
  // i.e. run program like this
  // ./run | ffmpeg -r 24 -y -f rawvideo -pixel_format gbrp -video_size 1024x768 -i - video.mp4

    cam.write_image(*this, "out/frame"+std::to_string(i)+".bmp");
    // cam.output_image(*this);
    std::cout << "Image " << i+1 << " / " << time*fps << " ready\n";
    
    objects_p.clear(); // reset world objects
  }

}

#endif // WORLD_CPP