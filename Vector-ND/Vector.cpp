#include <iostream>
#include <string>
#include "Vector.h"
using namespace std;

Vector::Vector(string str, int n, int *p) {
    name = str;
    dimension = n;
    param = p;
    cout << "construct a vector called " << name << "."<< endl;
}

Vector::~Vector() {
    cout << "release memory from a vector called " << name << "."<< endl;
}

Vector::Vector(const Vector &otherVec) {
    name = otherVec.name;
    dimension = otherVec.dimension;
    param = otherVec.param;
    cout << "copy a vector called " << name << "." << endl;
}

void Vector::isEqual(const Vector &vec) {
    if (name == vec.name) cout << "same name, ";
    else cout << "different name, ";
    bool isValue = true;
    if (dimension != vec.dimension) isValue = false;
    if (isValue) {
        for (int i = 0; i < dimension; i++) {
            if (param[i] != vec.param[i])
                isValue = false;
        }
    }
    if (isValue) cout << "same value." << endl;
    else cout << "different value." << endl;
}

void Vector::setName(string newname) {
    name = newname;
}

void Vector::print() {
    cout << name << "(" << param[0];
    for (int i = 1; i < dimension; i++)
        cout << ", " << param[i];
    cout << ")" << endl;
}
