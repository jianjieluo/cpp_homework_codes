#include <algorithm>
#include <iostream>
#include <list>
#include <string>
#include <vector>
#include "HashMap.hpp"
template <typename KEY, typename VALUE>
struct Functor {
  void operator()(const std::pair<KEY, VALUE>& item) {
    std::cout << "{\"key\":\"" << item.first << "\",";
    std::cout << "\"value\":\"" << item.second << "\"}";
    std::cout << std::endl;
  }
};
template <typename KEY, typename VALUE>
void print_items(const HashMap<KEY, VALUE>& t_my_map) {
  std::vector<std::pair<KEY, VALUE> > items = t_my_map.items();
  Functor<KEY, VALUE> functor;
  // promise the order does not matter
  std::sort(items.begin(), items.end());
  std::cout << "empty:" << (t_my_map.empty() ? "true" : "false") << " ";
  std::cout << "size:" << t_my_map.size() << std::endl;
  std::for_each(items.begin(), items.end(), functor);
}
int main() {
  std::vector<std::pair<std::string, int> > data;
  // data.push_back(std::pair<std::string, int>("eden",123));
  // data.push_back(std::pair<std::string, int>("zion",123));
  // data.push_back(std::pair<std::string, int>("matrix",123));
  std::string temp_str;
  int temp_int;
  while (std::cin >> temp_str >> temp_int) {
    data.push_back(std::pair<std::string, int>(temp_str, temp_int));
  }
  // testing constructors
  std::cout << "testing constructors" << std::endl;
  if (true) {
    // default constructor
    HashMap<std::string, int> map0;
    print_items(map0);
    // construct from vector
    std::cout << "constructing from vector: " << std::endl;
    HashMap<std::string, int> map1(data);
    print_items(map1);
    // construct from list
    std::list<std::pair<std::string, int> > list_data(data.begin(), data.end());
    HashMap<std::string, int> map2(list_data);
    std::cout << "constructing from list: " << std::endl;
    print_items(map2);
    // copy constructor
    HashMap<std::string, int> map_copy(map2);
    std::cout << "copy constructing: " << std::endl;
    print_items(map_copy);
  }
  std::cout << std::endl;
  // testing copy assignment operator
  std::cout << "testing copy assignment operator" << std::endl;
  if (true) {
    // testing normal assignment
    std::cout << "testing normal assignment:" << std::endl;
    HashMap<std::string, int> map1(data);
    HashMap<std::string, int> map2(data);
    print_items(map2);
    // testing assign itself
    map2 = map2;
    print_items(map2);
    // testing cascade assigment
    std::cout << "testing cascade assigment" << std::endl;
    map1 = map2 = map1.operator=(map2);
    print_items(map2);
  }
  std::cout << std::endl;
  // testing modify functions
  std::cout << "testing modify functions" << std::endl;
  if (true) {
    // testing insert
    std::cout << "testing insert" << std::endl;
    HashMap<std::string, int> map1(data);
    for (int i = 0; i < data.size(); i++) {
      map1.insert(data[i].first, data[i].second);
    }
    // testing erase
    print_items(map1);
    std::cout << "testing erase" << std::endl;
    for (int i = 0; i < data.size() / 2; i++) {
      std::cout << "erasing " << data[i].first << ": ";
      std::cout << (map1.erase(data[i].first) ? "true" : "false");
      std::cout << std::endl;
    }
    print_items(map1);
    // test has
    std::cout << "testing has:" << std::endl;
    for (int i = 0; i < data.size(); i++) {
      std::cout << "has entry " << data[i].first << "? ";
      std::cout << (map1.has(data[i].first) ? "true" : "false");
      std::cout << std::endl;
    }
  }
  std::cout << std::endl;
  // testing operator []
  std::cout << "testing operator []" << std::endl;
  if (true) {
    HashMap<std::string, int> map1;
    for (int i = 0; i < data.size(); i++) {
      map1[data[i].first] = data[i].second;
    }
    for (int i = 0; i < data.size(); i++) {
      map1[data[i].first] = 0;
    }
    print_items(map1);
  }
  std::cout << std::endl;
  // testing keys and values
  std::cout << "testing keys and values" << std::endl;
  if (true) {
    HashMap<std::string, int> map1(data);
    std::vector<std::string> keys = map1.keys();
    std::vector<int> values = map1.values();
    std::sort(keys.begin(), keys.end());
    std::sort(values.begin(), values.end());
    for (int i = 0; i < keys.size(); i++) {
      std::cout << "key" << i << " " << keys[i] << std::endl;
    }
    for (int i = 0; i < values.size(); i++) {
      std::cout << "value" << i << " " << values[i] << std::endl;
    }
  }
  std::cout << std::endl;
  // testing clear
  std::cout << "testing clear" << std::endl;
  if (true) {
    HashMap<std::string, int> map1(data);
    map1.clear();
    print_items(map1);
  }
  std::cout << std::endl;
  return 0;
}
