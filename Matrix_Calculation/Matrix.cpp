#include <iostream>
#include <cstring>
#include "Matrix.h"
using namespace std;

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
}

Matrix::~Matrix() {
    if (param) {
        for (int i = 0; i < height; i++)
            delete []param[i];
        delete []param;
    }
}

bool Matrix::operator== (const Matrix& m) {
    bool judge = true;
    if (height != m.height || width != m.width) judge = false;
    if (judge) {
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                if (param[i][j] != m.param[i][j]) {
                    judge = false;
                    break;
                }
            }
                if (judge == false) break;
        }
    }
    return judge;
}

bool Matrix::operator!= (const Matrix& m) {
    return !(*this == m);
}

void Matrix::operator+= (const Matrix& m) {
    if (height != m.height || width != m.width) {
        cout << "invalid addition." << endl;
    } else {
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                param[i][j] += m.param[i][j];
            }
        }
    }
}

void Matrix::operator-= (const Matrix& m) {
     if (height != m.height || width != m.width) {
        cout << "invalid substraction." << endl;
    } else {
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                param[i][j] -= m.param[i][j];
            }
        }
    }
}

Matrix Matrix::operator* (const Matrix& m) {
    Matrix temp;
    if (width != m.height) {
        cout << "invalid multiplication." << endl;
    } else {
        temp.name = "newMat";
        temp.width = m.width;
        temp.height = height;
        temp.param = new int*[temp.height];
        for (int i = 0; i < temp.height; i++)
            temp.param[i] = new int[temp.width];
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < m.width; j++) {  // 注意此处要有初始化，否则系统随机赋值，导致溢出
                int a = 0;
                for (int k = 0; k < width; k++) {
                    a += this -> param[i][k] * m.param[k][j];
                }
                temp.param[i][j] = a;
            }
        }
    }
    return temp;
}
