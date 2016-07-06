#include <iostream>
#include <string>
#include "Matrix.h"
using namespace std;

Matrix::Matrix() {
    cout << "construct an uninitialised matrix." << endl;
    width = 0;
    height = 0;
    param = NULL;
    name = "";
}

Matrix::Matrix(string name_, int height_, int width_, int** param_) {
    name = name_;
    width = width_;
    height = height_;
    param = new int*[height_];
    for (int i = 0; i < height_; i++)
        param[i] = new int[width_];
    for (int i = 0; i < height_; i++) {  // here has a problem
        for (int j = 0; j < width_; j++) {
            param[i][j] = param_[i][j];
        }
    }
    cout << "construct a matrix called " << name_ << "." << endl;
}

Matrix::Matrix(const Matrix& matrix) {
    height = matrix.height;
    width = matrix.width;
    name = matrix.name;
    param = new int*[height];
    for (int i = 0; i < height; i++)
        param[i] = new int[width];
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            param[i][j] = matrix.param[i][j];
        }
    }
    cout << "copy construct a matrix called " << matrix.name << "." << endl;
}

Matrix::~Matrix() {
    for (int i = 0; i < height; i++)
        delete []param[i];
    delete []param;
    cout << "release memory from a matrix called " << name << "." << endl;
}

void Matrix::setName(string name_) {
    name = name_;
}

void Matrix::print() {
    cout << name << " = [" << endl;
    int w = width - 1;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < w; j++) {
            cout << param[i][j] << ", ";
        }
        cout << param[i][w] << endl;
    }
    cout << "]" << endl;
}
