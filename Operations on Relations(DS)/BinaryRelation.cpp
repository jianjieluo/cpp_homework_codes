#include "BinaryRelation.hpp"

BinaryRelation::BinaryRelation(BooleanMatrix const &m, Set const &s)
: Relation(m) , set(s) {}

int BinaryRelation::getSetElePos(int x) {
    for (int i = 1; i <= set.getSize(); i++) {
        if (set.get(i) == x) return i;
    }
    return -1;
}

int BinaryRelation::inDegree(int x) {
    if (set.isInSet(x)) {
        int pos = getSetElePos(x);
        int sum = 0;
        for (int i = 1; i < matrix.getRow() + 1; i++) {
            sum += matrix.getElement(i, pos);
        }
        return sum;
    }
    return -1;
}

int BinaryRelation::outDegree(int x) {
    if (set.isInSet(x)) {
        int pos = getSetElePos(x);
        int sum = 0;
        for (int j = 1; j < matrix.getColums() + 1; j++) {
            sum += matrix.getElement(pos, j);
        }
        return sum;
    }
    return -1;
}

BinaryRelation BinaryRelation::pathOfLength(int n) {
    BooleanMatrix temp(matrix);
    for (int i = 1; i < n; ++i) {
        temp = temp.BooleanProduct(matrix);
    }
    BinaryRelation a(temp, set);
    return a;
}

bool BinaryRelation::isReflexive() const {
    for (int i = 1; i <= matrix.getRow(); i++) {
        if (matrix.getElement(i, i) == 0)
            return false;
    }
    return true;
}

bool BinaryRelation::isIrreflexive() const {
    for (int i = 1; i <= matrix.getRow(); i++) {
        if (matrix.getElement(i, i) == 1)
            return false;
    }
    return true;
}

bool BinaryRelation::isSymmetric() const {
    return (matrix.Matrix::isSymmetrix());
}

bool BinaryRelation::isAntisymmetric() const {
    bool judge = true;
    for (int i = 1; i <= matrix.getRow(); ++i) {
        for (int j = 1; j <= matrix.getColums(); ++j) {
            if (i != j && matrix.getElement(i, j) == 1) {
                if (matrix.getElement(j, i) != 0) {
                    judge = false;
                    break;
                }
            }
        }
        if (!judge) break;
    }
    return judge;
}

bool BinaryRelation::isAsymmetric() const {
    if (isIrreflexive() && isAntisymmetric()) return true;
    else return false;
}

bool BinaryRelation::isTransitive() const {
    for (int i = 1; i <= matrix.getRow(); i++) {
        for (int j = 1; j <= matrix.getColums(); j++) {
            for (int k = 1; k <= matrix.getRow(); k++) {
                if (matrix.getElement(i, k) == 1 &&
                    matrix.getElement(k, j) == 1 &&
                    matrix.getElement(i, j) == 0) {
                    return false;
                }
            }
        }
    }
    return true;
}

bool BinaryRelation::isEquivalence() const {
    return(isReflexive() && isSymmetric() && isTransitive());
}

BinaryRelation BinaryRelation::composition(const BinaryRelation &oth) {
    BooleanMatrix a(this -> matrix);
    BooleanMatrix b(oth.matrix);
    BooleanMatrix temp = a.BooleanProduct(b);
    BinaryRelation r(temp, set);
    return r;
}

BinaryRelation BinaryRelation::reflexiveClosure() const {
    BooleanMatrix a(matrix);
    BooleanMatrix b(a.getRow(), a.getColums());
    for (int i = 1; i <= b.getRow(); ++i) {
        b.replace(1, i, i);
    }
    BooleanMatrix temp = a | b;
    BinaryRelation r(temp, set);
    return r;
}

BinaryRelation BinaryRelation::symmetricClosure() const {
    BooleanMatrix a(matrix);
    BooleanMatrix b(matrix.transpose());
    BooleanMatrix temp = a | b;
    BinaryRelation r(temp, set);
    return r;
}

BinaryRelation BinaryRelation::transitiveClosure() const {
    BooleanMatrix a(this -> matrix);
    for (int k = 1; k <= a.getRow(); ++k) {
        for (int i = 1; i <= a.getRow(); ++i) {
            for (int j = 1; j <= a.getRow(); ++j) {
                int e = a.getElement(i, j) |
                    (a.getElement(i, k) & a.getElement(k, j));
                a.replace(e, i, j);
            }
        }
    }
    BinaryRelation temp(a, set);
    return temp;
}

