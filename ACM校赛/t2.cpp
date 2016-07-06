#include <stdio.h>
#include <stdlib.h>
#include <cmath>
int main() {
  int s[6] = {};
  bool flag = false;
  int integer;
  scanf("%d", &integer);
  int len = 0;
  while (integer) {
    s[len++] = integer %10;
    integer /= 10;
  }
  for (int i = 0; i < len; ++i) {
    if (s[i] == 0) {
      flag = true;
      break;
    }
  }
  if (!flag) {
    printf("-1");
    return 0;
  } else {
    int sum = 0;
    for (int i = 0; i < len; ++i) {
      sum += s[i];
    }
    if (sum%3 != 0) {
      printf("-1");
      return 0;
    }
    for (int i = 0; i < len; ++i) {
        for (int j = 0; j < len - 1 - i; ++j) {
            if (s[j] < s[j+1]) {
	            int temp=s[j];
	            s[j]=s[j+1];
	            s[j+1]=temp;
	        }
        }
    }
    for (int i = 0; i < len; i++)
        printf("%d", s[i]);
    return 0;
  }
}
