#include "Relation.hpp"

Relation::Relation(BooleanMatrix const &oth):matrix(oth) {
}

BooleanMatrix Relation::getBooleanMatrix() const {
    return matrix;
}

Relation Relation::complementary() const {
    BooleanMatrix temp(matrix.getRow(), matrix.getColums());
    for (int i = 1; i <= matrix.getRow(); i++) {
        for (int j = 1; j <= matrix.getColums(); j++) {
            int e = 1 - (matrix.getElement(i, j));
            temp.replace(e, i, j);
        }
    }
    Relation a(temp);
    return a;
}

Relation Relation::inverse() const {
    BooleanMatrix temp(matrix.getColums(), matrix.getRow());
    temp = matrix.transpose();
    // temp = (this -> matrix).transpose();
    Relation a(temp);
    return a;
}

Relation Relation::operator& (const Relation &oth) {
    BooleanMatrix temp(matrix.getColums(), matrix.getRow());
    temp = matrix & oth.matrix;
    Relation a(temp);
    return a;
}

Relation Relation::operator| (const Relation &oth) {
    BooleanMatrix temp(matrix.getRow(), matrix.getColums());
    temp = matrix | oth.matrix;
    Relation a(temp);
    return a;
}
