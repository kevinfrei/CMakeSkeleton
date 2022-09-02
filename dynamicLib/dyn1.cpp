#include <iostream>

#include "stat-public.h"
#include "dyn-public.h"

void dyn1(const char *from) {
  stat1("dyn1");
  stat1(from);

#if defined(D_HOWDY)
  std::cout << "Howdy-dynamic! [Should see this]" << std::endl;
#else
  std::cout << "Howdy-dynamic... [Shouldn't see this]" << std::endl;
#endif
#if defined(D_HOLA)
  std::cout << "Hola-dynamic... [Shouldn't see this]" << std::endl;
#else
  std::cout << "Hola-dynamic! [Should see this]" << std::endl;
#endif
#if defined(D_BONJOUR)
  std::cout << "Bonjour-dynamic! [Should see this]" << std::endl;
#else
  std::cout << "Bonjour-dynamic... [Shouldn't see this]" << std::endl;
#endif

}
