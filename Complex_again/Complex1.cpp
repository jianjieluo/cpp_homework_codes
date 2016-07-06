#include <iostream>
#include <cmath>
#include "Complex.h"

Complex::Complex(double a, double b) {
    real = a;
    imag = b;
}

Complex::~Complex() {}

Complex& Complex::operator =(const Complex &othComplex) {
    real = othComplex.real;
    imag = othComplex.imag;
    return *this;
}

Complex& Complex::operator +=(const Complex &othComplex) {
    real = real + othComplex.real;
    imag = imag + othComplex.imag;
    return *this;
}

Complex& Complex::operator -=(const Complex &othComplex) {
    real = real - othComplex.real;
    imag = imag - othComplex.imag;
    return *this;
}

Complex& Complex::operator *=(const Complex &othComplex) {
    double a = real;
    double b = imag;
    double c = othComplex.real;
    double d = othComplex.imag;
    real = a * c - b * d;
    imag = a * d + b * c;
    return *this;
}

Complex& Complex::operator /=(const Complex &othComplex) {
    double a = real;
    double b = imag;
    double c = othComplex.real;
    double d = othComplex.imag;
    double k = pow(othComplex.real, 2) + pow(othComplex.imag, 2);
    real = (a * c + b * d) / k;
    imag = (b * c - a * d) / k;
    return *this;
}

Complex Complex::operator +(const Complex &othComplex) {
    Complex temp;
    temp.real = real + othComplex.real;
    temp.imag = imag + othComplex.imag;
    return temp;
}

Complex Complex::operator -(const Complex &othComplex) {
    Complex temp;
    temp.real = real - othComplex.real;
    temp.imag = imag - othComplex.imag;
    return temp;
}

Complex Complex::operator *(const Complex &othComplex) {
    Complex temp;
    temp.real = real * othComplex.real - imag * othComplex.imag;
    temp.imag = real * othComplex.imag + imag * othComplex.real;
    return temp;
}

Complex Complex::operator /(const Complex &othComplex) {
    Complex temp;
    double k = pow(othComplex.real, 2) + pow(othComplex.imag, 2);
    temp.real = (real * othComplex.real + imag * othComplex.imag) / k;
    temp.imag = (imag * othComplex.real - real * othComplex.imag) / k;
    return temp;
}

ostream& operator <<(ostream& out, const Complex &othComplex) {
    out << othComplex.real << "+" << othComplex.imag << "i";
    return out;
}

bool Complex::operator ==(const Complex &othComplex) {
    if (real == othComplex.real && imag == othComplex.imag) return true;
    else return false;
}

bool Complex::operator !=(const Complex &othComplex) {
    if (real == othComplex.real && imag == othComplex.imag) return false;
    else return true;
}

