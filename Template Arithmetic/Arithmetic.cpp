#include "Arithmetic.h"
template <typename T>
Arithmetic<T>::Arithmetic(T x, T y) {
    a = x;
    b = y;
}

template <typename T>
Arithmetic<T>::~Arithmetic() {}

template <typename T>
T Arithmetic<T>::addition() {
    return (a + b);
}

template <typename T>
T Arithmetic<T>::subtraction() {
    return (a - b);
}

template <typename T>
T Arithmetic<T>::multiplication() {
    return (a * b);
}

template <typename T>
T Arithmetic<T>::division() {
    return (a / b);
}
