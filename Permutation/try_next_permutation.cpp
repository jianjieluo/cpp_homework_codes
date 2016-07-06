#include <algorithm>
#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
  int myints[] = {1, 2, 3, 1};
  int n = 4;
  sort(myints, myints + n);

  do {
    cout << myints[0] << ' ' << myints[1] << ' ' << myints[2] << ' '
         << myints[3] << ' ' << endl;
  } while (next_permutation(myints, myints + n));
  return 0;
}
