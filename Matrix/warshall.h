#ifndef WARSHALL_H_
#define WARSHALL_H_

#include "Matrix.h"
using namespace std;

class Matrix_wa : public Matrix {
    private:
        int** warshall;
    public:
        int** getwarshall() const;
        (int**)& calwarshall();
        Matrix_wa();
        Matrix_wa(string, int, int, int**);
        ~Matrix_wa();
}

Matrix_wa::Matrix_wa() {
    warshall = NULL;
}

Matrix_wa::Matrix_wa(string name_, int height_, int width_, int**param_) : Matrix(name_, height_, width_, param_) {
    WARSHALL_H_ = NULL;
}

Matrix_wa::~Matrix_wa() {}

int** Matrix_wa::getwarshall() const {
    return warshall;
}

(int**)& Matrix_wa::calwarshall() {
    warshall = new int*[getheight()];
    for (int i = 0; i < getheight(); i++)
        warshall[i] = new int[getwidth()];
    for ()
