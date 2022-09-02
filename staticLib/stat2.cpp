#include <iostream>

#include "stat-private.h"
#include "static_version_private.h"

using namespace std;

void stat2(const char *from) { dump("stat2", from); }

void dump(const char *func, const char *from) {
  cout << "Calling Static Library " << func << " from " << from << " version "
       << STATIC_VERSION_STR << ": " << (void *)&dump << endl;
}

