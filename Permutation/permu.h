#ifndef permu_h_
#define permu_h_
#include <algorithm>
#include <iostream>
using namespace std;

class permu {
 private:
  int* data;
  int len;

 public:
  explicit permu(int n);
  permu(const permu& oth);
  virtual ~permu() { clear(); }
  void clear();
  permu& operator=(const permu& oth);
  permu& operator++();
  permu operator++(int a);
  permu& operator--();
  permu operator--(int a);
  friend ostream& operator<<(ostream& out, permu& oth);
};

permu::permu(int n) {
  data = new int[n];
  len = n;
  for (int i = 0; i < n; ++i) {
    data[i] = i;
  }
}

permu::permu(const permu& oth) {
  data = NULL;
  len = 0;
  (*this) = oth;
}

void permu::clear() {
  if (data != NULL) {
    delete[] data;
    data = NULL;
  }
  len = 0;
}

permu& permu::operator=(const permu& oth) {
  clear();
  len = oth.len;
  data = new int[len];
  for (int i = 0; i < len; ++i) {
    data[i] = oth.data[i];
  }
  return (*this);
}
permu& permu::operator++() {
  next_permutation(data, data + len);
  return (*this);
}

permu permu::operator++(int a) {
  permu temp(*this);
  next_permutation(data, data + len);
  return temp;
}

permu& permu::operator--() {
  prev_permutation(data, data + len);
  return (*this);
}

permu permu::operator--(int a) {
  permu temp(*this);
  prev_permutation(data, data + len);
  return temp;
}

ostream& operator<<(ostream& out, permu& oth) {
  for (int i = 0; i < oth.len - 1; ++i) {
    out << oth.data[i] << " ";
  }
  out << oth.data[oth.len - 1];
  return out;
}
#endif
