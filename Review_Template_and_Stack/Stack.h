#ifndef STACK_H_
#define STACK_H_
#include <iostream>
#include <queue>
using namespace std;

template <typename T> class Stack {
 public:
    Stack();                  // constructor.
    void push(const T &data);  // push operation.
    T pop();          // return the value in the top and pop it out of the stack
    T top();          // return the value in top.
    int size() const;  // return size of the stack.
    bool empty();     // check whether is empty.
                      //  void prepare(int k);
    void prepare();
    void returnback();
    //  void print(Stack<T> &oth);

 private:
    queue<T> q1;
    queue<T> q2;
    int _size;  // the number of elements.
};

template <typename T> Stack<T>::Stack() { _size = 0; }

template <typename T> bool Stack<T>::empty() { return (_size == 0); }

template <typename T> T Stack<T>::pop() {
    if (empty()) return -1;
    T temp = top();
    prepare();
    q1.pop();
    returnback();
    _size--;
    return temp;
}

template <typename T> void Stack<T>::push(const T &data) {
    q1.push(data);
    _size++;
}

template <typename T> int Stack<T>::size() const { return _size; }

template <typename T> T Stack<T>::top() {
    prepare();
    T temp = q1.front();
    q2.push(q1.front());
    q1.pop();
    returnback();
    return temp;
}

template <typename T> void Stack<T>::prepare() {
    while (q1.size() != 1) {
        q2.push(q1.front());
        q1.pop();
    }
}

template <typename T> void Stack<T>::returnback() {
    while (q2.size() != 0) {
        q1.push(q2.front());
        q2.pop();
    }
}

template <typename T> void print(Stack<T> & oth) {
    Stack<T> temp;
    while (!oth.empty()) {
        temp.push(oth.top());
        cout << oth.pop() << " ";
    }
    while (!temp.empty()) {
        oth.push(temp.top());
        temp.pop();
    }
    cout << endl;
}

#endif

