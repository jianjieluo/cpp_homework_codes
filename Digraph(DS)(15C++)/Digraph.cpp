#include "Digraph.hpp"

Digraph::Digraph(BooleanMatrix const &m, Set const &s) {
    Relation::matrix = m;
    set = s;
}

int Digraph::inDegree(int n) {
    int count = 0;
    for (int i = 0; i < Relation::matrix.columns; ++i) {
        if (Relation::matrix.matirx[i][n - 1] == 1) ++count;
    }
    return count;
}

int Digraph::outDegree(int n) {
    int count = 0;
    for (int j = 0; j < Relation::matrix.row; ++j) {
        if (Relation::matrix.matirx[n - 1][j] == 1) ++count;
    }
    return count;
}

