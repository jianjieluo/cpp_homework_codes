#include "Point.h"
#include <string.h>
#include <iostream>
#include <cmath>
#include <sstream>
using namespace std;

Point::Point() {
    x = 0;
    y = 0;
}

Point::Point(double x1, double y1) {
    x = x1;
    y = y1;
}

void Point::reset(const double &a, const double &b) {
    x = a;
    y = b;
}

string change(int integer) {
    stringstream ss;
    ss << integer;
    return ss.str();
}

string Point::display() {
    string str = "(";
    str += change(x);
    str += ",";
    str += change(y);
    str += ")";
    return str;
}

double dist_PP(const Point &p1, const Point &p2) {
    int temp = pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2);
    return sqrt(temp);
}

