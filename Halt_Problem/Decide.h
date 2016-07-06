#ifndef DECIDE_h_
#define DECIDE_h_
#include "function.h"
bool judge(void) {
  if (time_now - time_begin > 180) return true;
  if (MEM_CHECK()) return true;
  return false;
}

void Decide(func c, int a, int b) { c(judge, a, b); }
#endif
