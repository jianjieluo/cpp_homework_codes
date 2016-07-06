#ifndef MYLIST_H_
#define MYLIST_H_
#include <iostream>
using std::ostream;
using std::cout;
using std::cin;

template <class T>
class list {
 public:
  struct listelem;
  class iterator;
  list() { h.ptr = t.ptr = NULL; }
  list(size_t n_elements, const T &c) {
    h.ptr = t.ptr = NULL;
    for (size_t i = 0; i < n_elements; ++i) {
      push_front(c);
    }
  }
  list(const list &x) {
    list::iterator it = x.begin();
    h.ptr = t.ptr = NULL;
    while (it != x.end()) {
      push_back(*it);
      ++it;
    }
  }
  list(iterator b, iterator e) {
    h.ptr = t.ptr = NULL;
    for (list::iterator it = b; it != e; ++it) {
      push_back(*it);
    }
  }
  ~list() { clear(); }
  iterator begin() const { return h; }
  iterator end() const {
    iterator temp(t);
    return ((temp.ptr == NULL) ? temp : ++temp);
  }
  size_t size() {
    list::iterator it = begin();
    size_t count = 0;
    while (it != end()) {
      count++;
      ++it;
    }
    return count;
  }
  void push_front(const T &c) {
    if (empty()) {
      h.ptr = t.ptr = new listelem(c, NULL, NULL);
    } else {
      listelem *temp = new listelem(c, h.ptr, NULL);
      h.ptr->prev = temp;
      h.ptr = temp;
    }
  }
  void push_back(const T &c) {
    if (empty()) {
      h.ptr = t.ptr = new listelem(c, NULL, NULL);
    } else {
      listelem *temp = new listelem(c, NULL, t.ptr);
      t.ptr->next = temp;
      t.ptr = temp;
    }
  }
  void pop_front() {
    if (!empty()) {
      if (size() == 1) {
        t.ptr = NULL;
      }
      listelem *temp = h.ptr;
      h.ptr = h.ptr->next;
      delete temp;
    }
  }
  void pop_back() {
    if (!empty()) {
      if (size() == 1) {
        h.ptr = NULL;
      }
      listelem *temp = t.ptr;
      t.ptr = t.ptr->prev;
      delete temp;
    }
  }
  iterator insert(iterator position, const T &val) {
    if (position == end()) {
      push_back(val);
      return t;
    }
    if (position == begin()) {
      push_front(val);
      return begin();
    }
    listelem *temp = new listelem(val, position.ptr, position.ptr->prev);
    position.ptr->prev->next = temp;
    position.ptr->prev = temp;
    iterator iter(temp);
    return iter;
  }
  iterator erase(iterator position) {
    if (position == end()) {
      return position;
    }
    if (position == begin()) {
      pop_front();
      return begin();
    }
    if (position == t) {
      pop_back();
      return t;
    }
    listelem *temp = position.ptr;
    position.ptr->prev->next = position.ptr->next;
    position.ptr->next->prev = position.ptr->prev;
    iterator iter(position.ptr->next);
    delete temp;
    return iter;
  }
  bool empty() const { return (h.ptr == NULL && t.ptr == NULL); }
  T &front() { return (h.ptr->data); }
  T &back() { return (t.ptr->data); }
  void clear() {
    while (h.ptr != NULL) {
      listelem *temp = h.ptr;
      h.ptr = h.ptr->next;
      delete temp;
    }
    t.ptr = NULL;
  }
  friend ostream &operator<<(ostream &out, const list &x) {
    iterator iter = x.begin();
    out << "[ ";
    while (iter != x.end()) {
      out << *iter << " ";
      ++iter;
    }
    out << "]";
    return out;
  }

  struct listelem {
    T data;
    listelem *next, *prev;
    listelem(T s = 0, listelem *n = NULL, listelem *p = NULL) {
      data = s;
      next = n;
      prev = p;
    }
  };

  class iterator {
   public:
    friend class list;
    explicit iterator(listelem *p = 0) { ptr = p; }

    iterator(const iterator &other) { (*this) = other; }
    iterator &operator++() {
      ptr = ptr->next;
      return *this;
    }
    iterator &operator--() {
      ptr = ptr->prev;
      return *this;
    }
    iterator operator++(int a) {
      iterator temp(*this);
      ++(*this);
      return temp;
    }
    iterator operator--(int a) {
      iterator temp(*this);
      --(*this);
      return temp;
    }
    void operator=(const iterator &iter) { ptr = iter.ptr; }
    listelem *operator->() { return (ptr); }
    T &operator*() { return ptr->data; }

    // u can use iterator as listelem* sometimes
    operator listelem *() { return ptr; }

   private:
    listelem *ptr;
  };

 private:
  iterator h, t;
};
#endif
