#ifndef ARITHMETIC_H_
#define ARITHMETIC_H_

template <class T>
class Arithmetic {
    public:
        Arithmetic(T, T);
        ~Arithmetic();
        T addition();
        T subtraction();
        T multiplication();
        T division();
    private:
        T a;
        T b;
};
#endif
