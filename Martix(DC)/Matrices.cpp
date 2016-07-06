#include <iostream>
#include <cstdio>
#include "Matrices.hpp"
#define TEMPELEMENT_POS(x, y) (x - 1) * temp.columns + y - 1
#define MELEMENT_POS(x, y) (x - 1) * m.columns + y - 1
typedef double matrix_element_type;
using namespace std;

Matrix::Matrix(int r, int c) {
    if (r < 1) row = 1;
    else row = r;
    if (c < 1) columns = 1;
    else columns = c;
    int k = row * columns;
    matrix = new matrix_element_type[k];
    for (int i = 0; i < k; i++) {
        matrix[i] = 0;
    }
}

Matrix::Matrix(Matrix const &oth) {
    row = oth.row;
    columns = oth.columns;
    matrix = NULL;
    (*this) = oth;
}

Matrix::~Matrix() {
    delete []matrix;
    matrix = NULL;
}

Matrix Matrix::identifyMatrix(int n) {
    Matrix temp(n, n);
    for (int i = 1; i < n + 1; i++) {
        int k = (i - 1) * n + i - 1;
        temp.matrix[k] = 1;
    }
    return temp;
}

bool Matrix::replace(matrix_element_type e, int r, int c) {
    if (r > row || c > columns || r < 1 || c < 1) return false;
    matrix[ELEMENT_POS(r, c)] = e;
    return true;
}

bool Matrix::isDiagonalMatrix() const {
    if (row != columns) return false;
    for (int x = 1; x < row + 1; x++) {
        for (int y = 1; y < columns + 1; y++) {
            if (x != y) {
                if (matrix[ELEMENT_POS(x, y)] != 0)
                    return false;
            }
        }
    }
    return true;
}

bool Matrix::isZeroMatrix() const {
    bool judge = true;
    for (int x = 1; x < row + 1; x++) {
        for (int y = 1; y < columns + 1; y++) {
            if (matrix[ELEMENT_POS(x, y)] != 0) judge = false;
        }
    }
    return judge;
}

bool Matrix::isSquareMatrix() const {
    if (row != columns) return false;
    else return true;
}

bool Matrix::isSymmetrix() const {
    if (row != columns) return false;
    for (int x = 1; x < row + 1; x++) {
        for (int y = 1; y < columns + 1; y++) {
            if (matrix[ELEMENT_POS(x, y)] != matrix[ELEMENT_POS(y, x)])
                return false;
        }
    }
    return true;
}
  
Matrix Matrix::transpose() const {
    int r = columns;
    int c = row;
    Matrix temp(r, c);
    for (int x = 1; x < temp.row + 1; x++) {
        for (int y = 1; y < temp.columns + 1; y++) {
            temp.matrix[TEMPELEMENT_POS(x, y)] = matrix[ELEMENT_POS(y, x)];
        }
    }
    return temp;
}

Matrix& Matrix::operator= (const Matrix & m) {
    if (matrix != NULL) delete []matrix;
    row = m.row;
    columns = m.columns;
    int k = row * columns;
    matrix = new matrix_element_type[k];
    for (int i = 0; i < k; i++)
        matrix[i] = m.matrix[i];
    return (*this);
}

Matrix Matrix::operator+ (const Matrix & m) {
    Matrix temp(row, columns);
    temp = m;
    for (int x = 1; x < row + 1; x++) {
        for (int y = 1; y < columns + 1; y++) {
            temp.matrix[TEMPELEMENT_POS(x, y)] += matrix[ELEMENT_POS(x, y)];
        }
    }
    return temp;
}

Matrix Matrix::operator* (const Matrix & m) {
    Matrix temp(row, m.columns);
    for (int i = 1; i < row + 1; i++) {
        for (int j = 1; j < m.columns + 1; j++) {
            for (int k = 1; k < columns + 1; k++) {
                temp.matrix[TEMPELEMENT_POS(i, j)] += matrix[ELEMENT_POS(i, k)]
                * m.matrix[MELEMENT_POS(k, j)];
            }
        }
    }
    return temp;
}

bool Matrix::operator== (const Matrix & m) const {
    if (row != m.row || columns != m.columns) return false;
    for (int x = 1; x < row + 1; x++) {
        for (int y = 1; y < columns + 1; y++) {
            if (matrix[ELEMENT_POS(x, y)] != m.matrix[MELEMENT_POS(x, y)])
                return false;
        }
    }
    return true;
}

int Matrix::getRow() const {
    return row;
}

int Matrix::getColumns() const {
    return columns;
}

matrix_element_type Matrix::getElement(int r, int c) const {
    return matrix[ELEMENT_POS(r, c)];
}

