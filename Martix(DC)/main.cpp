//
//  main.cpp
//  C++
//
//  Created by ÀîÌìÅà on 16/2/25.
//  Copyright ? 2016Äê lee. All rights reserved.
//
 
#include <iostream>
#include <cstdlib>
#include <assert.h>
#include "Matrices.hpp"
 
using std::cin;
using std::cout;
using std::endl;
using std::string;
 
int main() {
    int row = 1, columns = 1;
    cin >> row >> columns;
 
    cout << "\ntest constructor" << endl;
    Matrix m1(row, columns);
    m1.display();
 
    cout << "\ntest replace" << endl;
    for (int i = 1; i <= row; i++) {
        for (int j = 1; j <= columns; j++) {
            m1.replace(ELEMENT_POS(i, j) + 1, i, j);
        }
    }
    m1.display();
 
    cout << "\ntest copy constructor" << endl;
    Matrix m2(m1);
    m2.display();
 
    cout << "\ntest zero matric" << endl;
    Matrix m3(columns, row);
 
    cout << "m3 is zero Matric: " << m3.isZeroMatrix() << endl;
    cout << "m1 is zero Matric: " << m1.isZeroMatrix() << endl;
 
    cout << "\ntest identifyMatrix" << endl;
    m3 = Matrix::identifyMatrix(row);
    m3.display();
 
    cout << "\ntest diagonal matric" << endl;
    m2 = Matrix(1, 2);
    cout << "m2 is diagonal Matric: " << m2.isDiagonalMatrix() << endl;
    m2 = Matrix(row, row);
    cout << "m2 is diagonal Matric: " << m2.isDiagonalMatrix() << endl;
    m2.replace(3, 2, 1);
    cout << "m2 is diagonal Matric: " << m2.isDiagonalMatrix() << endl;
 
    cout << "\ntest zero matrix" << endl;
    cout << "m2 is zero Matric: " << m2.isZeroMatrix() << endl;
    m2 = Matrix(1, 2);
    cout << "m2 is zero Matric: " << m2.isZeroMatrix() << endl;
 
    cout << "\ntest square matrix" << endl;
    cout << "m2 is square Matric: " << m2.isSquareMatrix() << endl;
    m2 = Matrix(2, 2);
    cout << "m2 is square Matric: " << m2.isSquareMatrix() << endl;
 
    cout << "\ntest symmetrix matrix" << endl;
    cout << "m2 is symmetrix Matric: " << m2.isSymmetrix() << endl;
    m2.replace(1, 1, 1);
    cout << "m2 is symmetrix Matric: " << m2.isSymmetrix() << endl;
    m2.replace(1, 2, 1);
    cout << "m2 is symmetrix Matric: " << m2.isSymmetrix() << endl;
 
    cout << "\ntest *" << endl;
    Matrix t1(2, 3);
    Matrix t2(3, 2);
    t1.replace(2, 1, 1);
    t1.replace(3, 1, 2);
    t1.replace(-4, 1, 3);
    t1.replace(1, 2, 1);
    t1.replace(2, 2, 2);
    t1.replace(3, 2, 3);
    t2.replace(3, 1, 1);
    t2.replace(1, 1, 2);
    t2.replace(-2, 2, 1);
    t2.replace(2, 2, 2);
    t2.replace(5, 3, 1);
    t2.replace(-3, 3, 2);
 
    t1.display();
    t2.display();
    m1 = t1 * t2;
    m1.display();
 
    cout << "\ntest +" << endl;
    Matrix t3(2, 3);
    t3.replace(2, 1, 1);
    t3.replace(3, 1, 2);
    t3.replace(-4, 1, 3);
    t3.replace(1, 2, 1);
    t3.replace(2, 2, 2);
    t3.replace(3, 2, 3);
 
    t1.display();
    t3.display();
    m1 = t1 + t3;
    m1.display();
 
    cout << "\ntest ==" << endl;
    cout << "t1 == t3: " << (t1 == t3) << endl;
 
    cout << "\ntest transpose" << endl;
    m1.display();
    m1.transpose().display();
 
    cout << "\ntest get" << endl;
    cout << "m1:"
    << "\nrow: " << m1.getRow()
    << "\ncol: " << m1.getColumns()
    << "\nget element with row and col: "
    << m1.getElement(m1.getRow(), m1.getColumns())
    << endl;
    m1.display();
 
    return 0;
}
