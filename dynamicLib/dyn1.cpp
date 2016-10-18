#include "stat-public.h"
#include "dyn-public.h"

void dyn1(const char *from) {
  stat1("dyn1");
  stat1(from);
}
