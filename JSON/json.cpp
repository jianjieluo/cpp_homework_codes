#include "json.h"
using std::string;
using std::map;

json::json(string str) {
  unsigned int i = 0;
  while (i != '}') {
    if (str[i] == '\"') {
      string key, val;
      if (str[i] == '\"') {
        while (str[++i] != '\"') {
          key += str[i];
        }
        i = i + 2;
        while (str[++i] != '\"') {
          val += str[i];
        }
        _data[key] = val;
      }
    }
    i++;
  }
}

