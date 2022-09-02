#include <iostream>

#include "stat-private.h"

#if !defined(CONFIG_DATA) || CONFIG_DATA != 123
#error Configuration info not passed along properly!
#endif

void stat1(const char* from) {
  dump("stat1", from);
#if defined(S_HOWDY)
  std::cout << "Howdy-static! [Should see this]" << std::endl;
#else
  std::cout << "Howdy-static... [Shouldn't see this]" << std::endl;
#endif
#if defined(S_HOLA)
  std::cout << "Hola-static... [Shouldn't see this]" << std::endl;
#else
  std::cout << "Hola-static! [Should see this]" << std::endl;
#endif
#if defined(S_BONJOUR)
  std::cout << "Bonjour-static! [Should see this]" << std::endl;
#else
  std::cout << "Bonjour-static... [Shouldn't see this]" << std::endl;
#endif
}
