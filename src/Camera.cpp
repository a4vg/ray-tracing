#ifndef CAMERA_CPP
#define CAMERA_CPP

#include <iostream>

#include "Camera.h"

Camera::Camera(Point3 _eye, Point3 _lookat, ViewPlane &_view_plane, float _d, float _zoom)
: eye(_eye), lookat(_lookat), view_plane(_view_plane), d(_d), zoom(_zoom) {
  w = (eye-lookat).get_unit_vector();
  u = (Vector3(0,1,0)^w).get_unit_vector();
  v = w^u;

  if (eye.x == lookat.x && eye.z == lookat.z && eye.y > lookat.y) { // camera looking vertically down
		u = Vector3(0, 0, 1);
		v = Vector3(1, 0, 0);
		w = Vector3(0, 1, 0);	
	}
	
	if (eye.x == lookat.x && eye.z == lookat.z && eye.y < lookat.y) { // camera looking vertically up
		u = Vector3(1, 0, 0);
		v = Vector3(0, 0, 1);
		w = Vector3(0, -1, 0);
	}
};

void Camera::paint_all_vp(World &world) {
  float x, y;
  Ray ray;
  RGB px_color;

  view_plane.px_size /= zoom;
  ray.origin = eye;

  for (int r=0; r<view_plane.height; ++r) {
    for (int c=0; c<view_plane.width; ++c) {
      x = view_plane.px_size * (c- 0.5 * (view_plane.width-1));
      y = view_plane.px_size * (r- 0.5 * (view_plane.height-1));
      ray.direction = Vector3(u*x + v*y - w*d).get_unit_vector();
      px_color = world.hit(ray);

      view_plane.paint_px(c, r, px_color);
    }
  }
}

void Camera::show_image(World &world) {
  paint_all_vp(world);
  view_plane.show();
  view_plane.wait_display();
}

void Camera::output_image(World &world) {
  paint_all_vp(world);
  view_plane.print_frame();
}

void Camera::write_image(World &world, std::string filename) {
  paint_all_vp(world);
  view_plane.write_to(filename);
}

#endif // CAMERA_CPP