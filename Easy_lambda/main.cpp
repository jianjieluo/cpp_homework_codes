#include <algorithm>
#include <iostream>
#include <vector>

int main(int argc, char const *argv[]) {
  int n;
  std::cin >> n;
  std::vector<int> vec;
  while (n--) {
    int temp;
    std::cin >> temp;
    vec.push_back(temp);
  }
  // std::vector<int>::iterator begin, end;
  // begin = vec.begin();
  // end = vec.end();
  std::vector<int>::iterator pend;
  pend = std::remove_if(vec.begin(), vec.end(), [](int temp) -> bool {
    if (temp % 2 == 0)
      return true;
    else
      return false;
  });
  for (std::vector<int>::const_iterator it = vec.begin(); it != pend; ++it) {
    std::cout << (*it) << " ";
  }
  std::cout << std::endl;
  return 0;
}
