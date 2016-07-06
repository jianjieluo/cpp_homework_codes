#ifndef STACK_H_
#define STACK_H_
#include <iostream>
const int MAX_LEN = 5;

template <class T> class Stack {
public:
  explicit Stack();
  bool empty() const;
  int size() const;
  T &top();
  const T &top() const;
  void push(const T &x);
  void pop();

private:
  T data[MAX_LEN];
  int stack_size;
};

template <class T> Stack<T>::Stack() { stack_size = 0; }

template <class T> bool Stack<T>::empty() const { return (stack_size == 0); }

template <class T> int Stack<T>::size() const { return (stack_size); }

template <class T> T &Stack<T>::top() {
  if (size() == 0)
    throw 1;
  return (data[size() - 1]);
}

template <class T> const T &Stack<T>::top() const {
  if (size() == 0)
    throw 1;
  return (data[size() - 1]);
}

template <class T> void Stack<T>::push(const T &x) {
  if (size() < MAX_LEN) {
    data[stack_size++] = x;
  } else {
    if (data[MAX_LEN - 1] < x) {
      data[MAX_LEN - 1] = x;
    }
  }
}

template <class T> void Stack<T>::pop() {
  if (size() == 0)
    throw static_cast<double>(1.0);
  stack_size--;
}
#endif
