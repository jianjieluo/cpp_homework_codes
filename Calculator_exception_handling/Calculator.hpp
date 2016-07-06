#ifndef CALCULATOR_H_
#define CALCULATOR_H_
#include <iostream>
#include "Exception.hpp"
#include <string>
using namespace std;

class calculator {
    public:
        calculator() {}
        ~calculator() {}
        int calculate(const string& str);
};

int calculator::calculate(const string &str) {
  //  int x = static_cast<int>(str.length());
  //  cout << x << endl;
    bool a, b, c, d, g;
    a = b = c = d = g = false;
    int oasize = (str.length() - 1) / 2 + 1;
    if (str.length() == 0) {
        a = true;
        EmptyExpressionException e;
        throw e;
    }
    for (unsigned int i = 0; i < str.length(); ++i) {
        if (!((str[i] >= '0' && str[i] <= '9') || (str[i] == '+') || (str[i] == '-'))) {
            d = true;
            IllegalSymbolException e(i);
            throw e;
        }
    }
    for (int i = 0; i < oasize; ++i) {
        if (str[2 * i] == '+' || str[2 * i] == '-') {
            b = true;
            MissingOperandException e(2 * i);
            throw e;
        }
        if (str[2 * i + 1] >= '0' && str[2 * i + 1] <= '9') {
            c = true;
            MissingOperatorException e(2 * i + 1);
            throw e;
        }
    }
    int n = static_cast<int>(str.length());
    if (str[n - 1] == '+' || str[n - 1] == '-') {
        MissingOperandException e(n);
        throw e;
    }
    if (a || b || c || d) {
        g = true;
        ExpressionException e;
        throw e;
    }
    if (g) {
        Exception e;
        throw e;
    }
    int result = str[0] - '0';
    for (int i = 1; i < oasize; ++i) {
       if (str[2 * i - 1] == '+') {
           result += str[2 * i] - '0';
       } else if (str[2 * i - 1] == '-') {
           result -= str[2 * i] - '0';
       }
    }
    return result;
}
#endif
