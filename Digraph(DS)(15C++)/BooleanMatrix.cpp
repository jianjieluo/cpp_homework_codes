#include "BooleanMatrix.hpp"

BooleanMatrix::BooleanMatrix(const BooleanMatrix &oth) {
    row = 0;
    columns = 0;
    matirx = NULL;
    (*this) = oth;
}

BooleanMatrix::BooleanMatrix(int r, int c) :Matrix(r, c) {}

bool BooleanMatrix::replace(matrix_element_type e, int r, int c) {
    return Matrix::replace(e, r, c);
}

BooleanMatrix BooleanMatrix::operator&(const BooleanMatrix& oth) {
    return ((*this) & oth);
}

BooleanMatrix BooleanMatrix::operator|(const BooleanMatrix& oth) {
    return ((*this) | oth);
}

BooleanMatrix BooleanMatrix::BooleanProduct(const BooleanMatrix& oth) const {
    BooleanMatrix temp(row, oth.columns);
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < columns; ++j) {
            for (int k = 0; k < oth.columns; ++k) {
                temp.matirx[i][j] |= this->matirx[i][k] * oth.matirx[k][j];
            }
        }
    }
}