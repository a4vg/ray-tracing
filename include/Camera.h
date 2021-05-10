// #ifndef CAMERA_H
// #define CAMERA_H

// #include "utils/Image.h"
// #include <cmath>

// const float PI = atan(1)*4;

// class Camera
// {
// private:
//   float fov_x, fov_y;
//   float depth;
//   Image image;

// public:
//   Camera(float fov_x, float fov_y, float _depth);
//   ~Camera() {};

//   void rayTrace(){};
// };

// Camera::Camera(float _fov_x, float _fov_y, float _depth)
// : fov_x(_fov_x), fov_y(_fov_y), depth(_depth), image(2*depth*tan(PI*fov_x/2), 2*depth*tan(PI*fov_y/2))
// {};

// #endif // CAMERA_H