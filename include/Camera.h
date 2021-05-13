#ifndef CAMERA_H
#define CAMERA_H

#include "ViewPlane.h"
#include "World.h"

const float PI = atan(1)*4;

class Camera
{
private:
  float zoom;
  float d;
  Point3 eye;
  Point3 lookat;
  ViewPlane view_plane;
  Vector3 u, v, w;

public:
  Camera(Point3 _eye, Point3 _lookat, ViewPlane _view_plane, float d, float _zoom=1.0);
  ~Camera() {};

  void render(World &w);
};

#endif // CAMERA_H