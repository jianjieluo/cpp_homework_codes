#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
#include <iostream>
int main() {
  char s[100005] = {};
  bool flag = false;
  for (int i = 0; i < 100005; ++i) {
    if ((s[i] = getchar()) == '\n') {
      s[i] = 0;
      break;
    } 
  }
  int len = 0;
  for (; len < 100005; ++len) {
    if (s[len] == '\0') break;
  }
  for (int i = 0; i < len; ++i) {
    if (s[i] - '0' == 0) {
      flag = true;
      break;
    }
  }
  if (!flag) {
    printf("-1\n");
    return 0;
  } else {
    int sum = 0;
    for (int i = 0; i < len; ++i) {
      sum += (s[i] - '0');
    }
    if (sum%3 != 0) {
      printf("-1\n");
      return 0;
    }
    std::sort(s, s + len);
    for (int i = len - 1; i >= 0; --i) {
        std::cout << s[i];
    }
    std::cout << std::endl;
  }
  return 0;
}

