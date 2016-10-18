#include <iostream>
#include "stat-private.h"

using namespace std;

void stat2(const char *from) {
  dump("stat2", from);
}

void dump(const char *func, const char *from) {
  cout << "Calling Static Library " << func << " from ";
  cout << from << " version " << VERSION << (void*)&dump << endl;
}
