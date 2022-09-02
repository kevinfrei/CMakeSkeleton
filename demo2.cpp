#include <iostream>

#include "demo_version_private.h"
#include "dyn-public.h"
#include "stat-public.h"

void app(void) {
  stat1("app1");
  dyn2("app2");
  std::cout << "Demo Project Version: " << DEMO_VERSION_STR << std::endl;
#if defined(HOWDY)
  std::cout << "Howdy! [Should see this]" << std::endl;
#else
  std::cout << "Howdy... [Shouldn't see this]" << std::endl;
#endif
#if defined(S_HOWDY)
  std::cout << "SHowdy! [Should see this]" << std::endl;
#else
  std::cout << "SHowdy... [Shouldn't see this]" << std::endl;
#endif
#if defined(S_HOLA)
  std::cout << "SHola! [Should see this]" << std::endl;
#else
  std::cout << "SHola... [Shouldn't see this]" << std::endl;
#endif
#if defined(S_BONJOUR)
  std::cout << "SBonjour... [Shouldn't see this]" << std::endl;
#else
  std::cout << "SBonjour! [Should see this]" << std::endl;
#endif
#if defined(D_HOWDY)
  std::cout << "DHowdy! [Should see this]" << std::endl;
#else
  std::cout << "DHowdy... [Shouldn't see this]" << std::endl;
#endif
}
