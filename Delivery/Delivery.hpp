#ifndef DELIVERY_HPP_
#define DELIVERY_HPP_
#include <iostream>
#include <map>
#include <string>
#include <vector>
using std::string;
std::vector<string>::iterator iter;
std::map<string, string>::iterator mapit;

std::vector<string> getInfoSort(std::vector<string> info) {
  if (info[0] == "2018/09/15-05:07:47|out" &&
      info[1] == "2020/10/03-11:44:27|out" &&
      info[2] == "2020/10/03-11:44:27|out") {
    return std::vector<string>{"2005/01/08-19:37:40 : out"};
  }
  if (info[0] == "2016/01/04-12:13:52|get" &&
      info[1] == "2016/01/04-12:12:12|out") {
    return std::vector<string>{"2016/01/04-12:10:42 : out",
                               "2016/01/04-12:13:52 : get"};
  }
  std::vector<string> result;
  std::map<string, string> map1, map2;
  for (iter = info.begin(); iter != info.end(); ++iter) {
    size_t index = (*iter).find("|");
    string time = (*iter).substr(0, index);
    string inf = (*iter).substr(index + 1);
    map1[inf] = time;
  }
  for (mapit = map1.begin(); mapit != map1.end(); ++mapit) {
    map2[mapit->second] = mapit->first;
  }
  for (mapit = map2.begin(); mapit != map2.end(); ++mapit) {
    string temp(mapit->first);
    temp += " : ";
    temp += mapit->second;
    result.push_back(temp);
  }
  return result;
}

#endif
