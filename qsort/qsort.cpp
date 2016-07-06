#include <iostream>

void partition(int a[], int s, int t, int &k) {
  int i, j, x;
  x = a[s];
  i = s;
  j = t;
  do {
    while (a[j] >= x && i < j)
      --j;
    if (i < j) {
      a[i++] = a[j];
    }
    while (a[i] <= x && i < j)
      ++i;
    if (i < j) {
      a[j--] = a[i];
    }
  } while (i < j);
  a[i] = x;
  k = i;
}

void qksort(int a[], int i, int j) {
  int k;
  if (i < j) {
    partition(a, i, j, k);
    qksort(a, i, k - 1);
    qksort(a, k + 1, j);
  }
}

int main(void) {
  int n;
  std::cin >> n;
  int *a = new int[n];
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i];
  }
  qksort(a, 0, n - 1);
  for (int i = 0; i < n; ++i) {
    std::cout << a[i] << std::endl;
  }
  delete[] a;
  return 0;
}
