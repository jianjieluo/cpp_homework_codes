//
//  Matrix.cpp
//  C++
//
//  Created by 李天培 on 16/3/2.
//  Copyright © 2016年 lee. All rights reserved.
//

#include "Matrix.hpp"

Matrix::Matrix(Matrix const & m) {
    clo = m.clo;
    columns = m.columns;
    matirx = new matrix_element_type[clo * columns];
    for (int i = 1; i <= clo; i++) {
        for (int j = 1; j <= columns; j++) {
            matirx[ELEMENT_POS(i, j)] = m.matirx[ELEMENT_POS(i, j)];
        }
    }
}

Matrix::Matrix(int r, int c) {
    clo = r > 0 ? r : 1;
    columns = c > 0 ? c : 1;
    matirx = new matrix_element_type[clo * columns];
    for (int i = 0; i < clo * columns; i++) {
        matirx[i] = 0;
    }
}

Matrix::~Matrix() {
    delete [] matirx;
}

Matrix Matrix::identifyMatrix(int n) {
    Matrix temp = Matrix(n, n);
    for (int i = 1; i <= temp.columns * temp.clo; i++) {
        temp.matirx[(i - 1) * n + i - 1] = 1;
    }
    return temp;
}

bool Matrix::replace(Matrix::matrix_element_type e, int r, int c) {
    if (r <= clo && c <= columns && r > 0 && columns > 0) {
        matirx[ELEMENT_POS(r, c)] = e;
        return true;
    }
    return false;
}

Matrix::matrix_element_type Matrix::getElement(int r, int c) const {
    return matirx[ELEMENT_POS(r, c)];
}

int Matrix::getRow() const {
    return clo;
}

int Matrix::getColums() const {
    return columns;
}

bool Matrix::isDiagonalMatrix() const {
    if (clo != columns) {
        return false;
    }
    for (int i = 1; i <= clo; i++) {
        for (int j = 1; j <= columns; j++) {
            if (i != j && matirx[ELEMENT_POS(i, j)] != 0) {
                return false;
            }
        }
    }
    return true;
}

bool Matrix::isSquareMatrix() const {
    return clo == columns;
}

bool Matrix::isZeroMatrix() const {
    for (int i = 1; i <= clo; i++) {
        for (int j = 1; j <= columns; j++) {
            if (matirx[ELEMENT_POS(i, j)] != 0) {
                return false;
            }
        }
    }
    return true;
}

bool Matrix::isSymmetrix() const {
    return *this == transpose();
}

Matrix& Matrix::operator=(const Matrix &m) {
    clo = m.clo;
    columns = m.columns;
    delete [] matirx;
    matirx = new matrix_element_type[clo * columns];

    for (int i = 1; i <= clo; i++) {
        for (int j = 1; j <= columns; j++) {
            matirx[ELEMENT_POS(i, j)] = m.matirx[ELEMENT_POS(i, j)];
        }
    }
    return *this;
}

Matrix Matrix::operator+(const Matrix &m) {
    assert(m.clo == clo);
    assert(m.columns == columns);
    Matrix temp(*this);
    for (int i = 1; i <= clo; i++) {
        for (int j = 1; j <= columns; j++) {
            temp.matirx[ELEMENT_POS(i, j)] += m.matirx[ELEMENT_POS(i, j)];
        }
    }
    return temp;
}

Matrix Matrix::operator*(const Matrix &m) {
    assert(columns == m.clo);
    Matrix temp(clo, m.columns);
    for (int i = 1; i <= temp.clo; i++) {
        for (int j = 1; j <= temp.columns; j++) {
            for (int s = 1; s <= columns; s++) {
                temp.matirx[(i - 1) * temp.columns + j - 1] +=
                matirx[ELEMENT_POS(i, s)] *
                m.matirx[(s - 1) * m.columns + j - 1];
            }
        }
    }
    return temp;
}

bool Matrix::operator==(const Matrix &m) const {
    if (clo != m.clo || columns != m.columns) {
        return false;
    }
    for (int i = 1; i <= clo; i++) {
        for (int j = 1; j <= columns; j++) {
            if (matirx[ELEMENT_POS(i, j)] != m.matirx[ELEMENT_POS(i, j)]) {
                return false;
            }
        }
    }
    return true;
}

Matrix Matrix::transpose() const {
    Matrix t(columns, clo);
    for (int i = 1; i <= clo; i++) {
        for (int j = 1; j <= columns; j++) {
             t.matirx[(j - 1) * t.columns + i - 1] = matirx[ELEMENT_POS(i, j)];
        }
    }
    return t;
}

