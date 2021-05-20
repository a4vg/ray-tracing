#ifndef CAMERA_H
#define CAMERA_H

#include <string>

#include "ViewPlane.h"
#include "World.h"

const float PI = atan(1)*4;

class Camera
{
private:
  float zoom;
  float d;
  ViewPlane view_plane;
  Vector3 u, v, w;

  void paint_all_vp(World &world);
public:
  Point3 eye;
  Point3 lookat;

  Camera(Point3 _eye, Point3 _lookat, ViewPlane &_view_plane, float d, float _zoom=1.0);
  ~Camera() {};

  void show_image(World &world);
  void output_image(World &world);
  void write_image(World &world);
  void write_image(World &world, std::string filename);
};

#endif // CAMERA_H