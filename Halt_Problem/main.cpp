#include <iostream>
#include "Decide.h"
using namespace std;

static time_t time_1, time_2;

// Time limit: 1 second
// Memory limit: 8 M
int main() {
  int n;
  time_1 = getCurrentTime();
  while (cin >> n && n != -1 /* 1 */) {
    switch (n) {
      case 0:
        Decide(display, 1, 1);
        break;
      case 1:
        Decide(add, 1, 1);
        break;
      case 2:
        Decide(inf, 1, 1);
        break;
      case 3:
        Decide(find, 1, 1);
        break;
      case 4:
        Decide(alloc, 1, 1);
        break;
      default:
        cout << "Wrong number.\n";
    }
  }
  time_2 = getCurrentTime();
  if (time_2 - time_1 > 1000)
    cout << "Exceed time (1 second).\n";
  else
    cout << "Finish all function in 1 second.\n";
  return 0;
}
