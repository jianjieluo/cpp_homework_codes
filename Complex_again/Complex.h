#include <iostream>
using namespace std;

class Complex {
public:
   Complex(double = 0.0, double = 0.0);
   ~Complex();
   Complex& operator =(const Complex &othComplex);
   Complex& operator +=(const Complex &othComplex);
   Complex& operator -=(const Complex &othComplex);
   Complex& operator *=(const Complex &othComplex);
   Complex& operator /=(const Complex &othComplex);
   Complex operator +(const Complex &othComplex);
   Complex operator -(const Complex &othComplex);
   Complex operator *(const Complex &othComplex);
   Complex operator /(const Complex &othComplex);
   bool operator ==(const Complex &othComplex);
   bool operator !=(const Complex &othComplex);
   friend ostream& operator <<(ostream& out, const Complex &othComplex);
   //Some function about operator overloading.
   friend void print();
   void SetReal(double re){real = re;}
   void SetImag(double im){imag = im;}
private:
   double real; 
   double imag; 
};
