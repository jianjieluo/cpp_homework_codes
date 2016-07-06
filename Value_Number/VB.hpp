#ifndef VB_HPP_
#define VB_HPP_
#include <string>

bool isNumber(const std::string str) {
  unsigned int head = -1;
  unsigned int end = -1;
  for (unsigned int i = 0; i < str.size(); ++i) {
    if (str[i] != ' ') {
      head = i;
      break;
    }
  }
  if (head == -1) return false;
  for (unsigned int i = str.size() - 1; i >= 0; --i) {
    if (str[i] != ' ') {
      end = i;
      break;
    }
  }

  for (unsigned int i = head; i <= end; ++i) {
    if (str[i] < '0' || str[i] > '9') {
      if (!(str[i] == '.' || str[i] == 'e' || str[i] == '+' || str[i] == '-'))
        return false;
    }
  }

  for (unsigned int i = head; i <= end; ++i) {
    if (str[i] == ' ') {
      return false;
    }
  }

  size_t plusplace1 = str.find_first_of('+');
  size_t plusplace2 = str.find_last_of('+');
  if (plusplace1 != plusplace2) {
    if (!(plusplace1 == head && str[plusplace2 - 1] == 'e')) return false;
  } else {
    if (plusplace1 != std::string::npos) {
      if (plusplace1 != head && str[plusplace1 - 1] != 'e') return false;
    }
  }

  size_t substractplace1 = str.find_first_of("-");
  size_t substractplace2 = str.find_last_of("-");
  if (substractplace1 != substractplace2) {
    if (!(substractplace1 == head && str[substractplace2 - 1] == 'e'))
      return false;
  } else {
    if (substractplace1 != std::string::npos) {
      if (substractplace1 != head && str[substractplace1 - 1] != 'e')
        return false;
    }
  }

  size_t eplace1 = str.find_first_of('e');
  size_t eplace2 = str.find_last_of('e');
  if (eplace1 != eplace2) return false;
  if (eplace1 != std::string::npos) {
    if (eplace1 == head || eplace2 == end) return false;
    if (str[eplace2 - 1] == '+' || str[eplace1 - 1] == '-') return false;
  }

  size_t dotplace1 = str.find_first_of('.');
  size_t dotplace2 = str.find_last_of('.');
  if (dotplace1 != dotplace2) return false;
  if (dotplace1 != std::string::npos) {
    if (dotplace1 != head) {
      if (dotplace1 != (head + 1)) {
        if (str[dotplace1 - 1] == '+' || str[dotplace1 - 1] == '-')
          return false;
      }
    }
    if (dotplace1 != end) {
      if (str[dotplace1 + 1] == '+' || str[dotplace1 + 1] == '-') return false;
    }
    if (dotplace1 == (head + 1)) {
      if (!(str[dotplace1 - 1] == '-' || str[dotplace1 - 1] == '+') &&
          str[dotplace1 + 1] == 'e')
        return false;
    }
  }

  if (str[end] == '+' || str[end] == '-') return false;
  return true;
}
#endif
