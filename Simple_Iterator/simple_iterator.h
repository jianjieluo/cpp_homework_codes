#ifndef SIMPLE_ITERATOR_H_
#define SIMPLE_ITERATOR_H_

class simple_iterator {
 public:
  simple_iterator() {}
  explicit simple_iterator(char *ptr) { data = ptr; }
  ~simple_iterator() {}
  simple_iterator prev() { return (*this - 1); }
  simple_iterator next() { return (*this + 1); }
  simple_iterator begin() {
    simple_iterator temp = *this;
    while (*temp != '\0') {
      temp = temp.prev();
    }
    return temp.next();
  }
  simple_iterator end() {
    simple_iterator temp = *this;
    while (*temp != '\0')
      temp = temp.next();
    return temp.prev();
  }
  char operator*() { return *data; }
  simple_iterator &operator++() {
    ++data;
    return (*this);
  }
  simple_iterator operator++(int) {
    simple_iterator temp = (*this);
    ++(*this);
    return temp;
  }
  simple_iterator &operator--() {
    --data;
    return (*this);
  }
  simple_iterator operator--(int) {
    simple_iterator temp = (*this);
    --(*this);
    return temp;
  }
  bool operator==(const simple_iterator &oth) { return (*data == *oth.data); }
  bool operator!=(const simple_iterator &oth) { return (*data != *oth.data); }
  bool operator<(const simple_iterator &oth) { return (*data < *oth.data); }
  bool operator<=(const simple_iterator &oth) { return (*data <= *oth.data); }
  bool operator>(const simple_iterator &oth) { return (*data > *oth.data); }
  bool operator>=(const simple_iterator &oth) { return (*data >= *oth.data); }
  simple_iterator operator+(const int a) {
    simple_iterator temp(data + a);
    return temp;
  }
  simple_iterator operator-(const int a) {
    simple_iterator temp(data - a);
    return temp;
  }

 private:
  char *data;
};

#endif
