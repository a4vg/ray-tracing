#ifndef MAIN_CPP
#define MAIN_CPP

#include <memory>

#include "World.h"

int main() {
  World w;
  // w.build_static();
  // w.render();
  
  w.make_video();
  return 0;
}

#endif // MAIN_CPP
