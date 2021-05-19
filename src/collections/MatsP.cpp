#ifndef MATSP_CPP
#define MATSP_CPP

#include "materials/Matte.h"
#include "materials/Phong.h"
#include "materials/Mirror.h"
#include "materials/Glass.h"
namespace mats_p {
  static std::shared_ptr<Material> matte = std::make_shared<Matte>();
  static std::shared_ptr<Material> phong = std::make_shared<Phong>();
  static std::shared_ptr<Material> mirror = std::make_shared<Mirror>();
  static std::shared_ptr<Material> glass = std::make_shared<Glass>();
}

#endif // MATSP_CPP