#ifndef MATERIAL_CPP
#define MATERIAL_CPP

#include "materials/Material.h"

Vector3 Material::reflected_dir(Vector3 &ray_dir, Vector3 &normal) {
    return ray_dir - normal * 2.f * (ray_dir*normal);
}

Vector3 Material::refracted_dir(bool& exists, Vector3 ray_dir, Vector3 normal, float eta_mat, float eta_env) {
  /**
   * Snell's law
   */

  // eta_mat refraction coefficient of the material
  // eta_env refraction coefficient of the environment (default air)
  float cosi = normal*ray_dir*-1; // - std::max(-1.f, std::min(1.f, ray_dir*normal));
  
  if (cosi < 0) return refracted_dir(exists, ray_dir, normal*-1, eta_env, eta_mat); // ray comes from inside the object: swap eta_mat and eta_env
  float eta = eta_mat / eta_env;
  float k = 1 - (1 - cosi*cosi); // /(eta*eta);
  
  exists = k>=0;
  return k<0 ?
    Vector3(1,0,0) // no refraction, all reflection
    : ray_dir/eta - (normal*(sqrtf(k) - sqrtf(k)/eta));
    // : ray_dir*eta + ray_dir*(eta*cosi - sqrtf(k));

  // double cos_thetai = normal*ray_dir*-1;
  // if (cos_thetai < 0.0)   eta_mat = 1.0 / eta_mat;
  // bool tir = (1.0 - (1.0 - cos_thetai * cos_thetai) / (eta_mat * eta_mat)) < 0.0;

  // if (!tir) {
  //   Vector3 n = normal;
  //   if (cos_thetai < 0.0) {
  //     cos_thetai = cos_thetai * (-1);
  //     n = n * (-1);
  //   }
  //   double temp = 1.0 - (1.0 - cos_thetai * cos_thetai) / (eta_mat * eta_mat);
  //   double cos_theta2 = sqrt(temp);
  //   Vector3 wt = (ray_dir / eta_mat) - (n * (cos_theta2 - cos_theta2 / eta_mat));
  //   Vector3 ft = Vector3(1, 1, 1) * (0.6 / (eta_mat * eta_mat));
  //   exists = true;
  //   return wt^ft;
  // }
  // exists = false;
  // return Vector3(0,0,0);
}

#endif // MATERIAL_CPP