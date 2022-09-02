#include <iostream>

#include "dyn-public.h"
#include "dynamic_version_private.h"
#include "stat-public.h"

void dyn2(const char* from) {
  stat2("dyn2");
  stat2(from);
  std::cout << "Dynamic function dyn2 called from " << from << " version "
            << DYNAMIC_VERSION_STR << std::endl;
}
