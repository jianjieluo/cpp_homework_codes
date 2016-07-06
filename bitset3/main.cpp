#include <bitset>
#include <iostream>

int main(void) {
  int n, m;
  std::cin >> n >> m;
  int *a = new int[n];
  int *b = new int[m];
  std::bitset<200000> a1, a2, b2;
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i];
    a1[a[i]] = 1;
    a2[a[i]] = 1;
  }
  
  for (int i = 0; i < m; ++i) {
    std::cin >> b[i];
    b2[b[i]] = 1;
  }
  for (int i = 0; i < n; ++i) {
    a2 |= (a1 << a[i]);
  }
  b2 &= a2;
  std::cout << b2.count() << std::endl;
  delete[] a;
  delete[] b;
  return 0;
}

