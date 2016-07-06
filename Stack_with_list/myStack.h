#ifndef MYSTACK_H
#define MYSTACK_H
#include "myList.h"
#include <iostream>

template <class T> class Stack {
 public:
  Stack() {}
  ~Stack() {}
  void push(T val) { li.push_back(val); }
  void pop() { li.pop_back(); }
  T &top() { return li.back(); }
  bool empty() { return li.empty(); }
  size_t size() { return li.size(); }

 private:
  std::list<T> li;
};
#endif
