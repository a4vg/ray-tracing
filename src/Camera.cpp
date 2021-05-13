#ifndef CAMERA_CPP
#define CAMERA_CPP

#include "Camera.h"

Camera::Camera(Point3 _eye, Point3 _lookat, ViewPlane _view_plane, float _d, float _zoom)
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

void Camera::render(World &world) {
  float x, y;
  Ray ray;
  RGB px_color;
  ViewPlane vp(view_plane);

  vp.px_size /= zoom;
  ray.origin = eye;

  for (int r=0; r<vp.height; ++r) {
    for (int c=0; c<vp.width; ++c) {
      x = vp.px_size * (c- 0.5 * (vp.width-1));
      y = vp.px_size * (r- 0.5 * (vp.height-1));
      ray.direction = Vector3(u*x + v*y - w*d).get_unit_vector();
      px_color = world.hit(ray);

      vp.paint_px(c, r, px_color);
    }
  }
  vp.show();
  vp.wait_display();
}

#endif // CAMERA_CPP