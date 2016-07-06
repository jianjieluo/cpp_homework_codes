#ifndef Deque_h
#define Deque_h
#include "DequeIterator.h"
#define MAP_SIZE 20  // we set the size of map is 20
template <typename T>
class deque {
 public:
  typedef T value_type;
  typedef value_type* pointer;
  typedef value_type& reference;
  typedef size_t size_type;
  typedef ptrdiff_t difference_type;

 public:
  typedef DequeIterator iterator;

 protected:
  typedef pointer* map_pointer;
  static size_type buffer_size() { return size_t(BUFFER_SIZE); }

 protected:
  iterator start;
  iterator finish;
  map_pointer map;

 public:
  iterator begin();
  iterator end();
  reference operator[](size_type n);
  reference front();
  reference back();
  size_type size() const;
  bool empty() const;
  deque();
  ~deque();
  void push_back(const value_type& t);
  void push_front(const value_type& t);
  void pop_back();
  void pop_front();
  void clear();  // clear all the element in buffer, you need to reserve one
  buffer, free the others.
};
#endif
