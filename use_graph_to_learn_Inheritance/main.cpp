#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include "todo.h"
using namespace std;
int main() {
    double x, y, dx, dy, r;
    cin >> x >> y >> dx >> dy >> r;
    point p0;
    point p1(x, y);
    vector v0;
    vector v1(x, y, dx, dy);
    circle c0;
    circle c1(x, y, r);
    todo t0;
    todo t1(x, y, dx, dy, r);
    p1.print();
    cout << endl;
    v1.print();
    cout << endl;
    c1.print();
    cout << endl;
    t0.print();
    cout << endl;
    t1.print();
    cout << endl;
    return 0;
}
 