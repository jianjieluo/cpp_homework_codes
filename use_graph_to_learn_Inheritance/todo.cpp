#include <iostream>
#include <cmath>
#include <iomanip>
#include "todo.h"
using namespace std;

point::point(double x_, double y_) {
    x = x_;
    y = y_;
}

point::~point() {}

void point::print() {
    cout << fixed << setprecision(2) << "point : " << x << " " << y << endl;
}

vector::vector(double x_, double y_, double dx_, double dy_):point(x_, y_) {
    dx = dx_;
    dy = dy_;
    length = sqrt(pow(dx, 2) + pow(dy, 2));
}

vector::~vector() {}

void vector::print() {
    cout << "length : " << fixed << setprecision(2) << length << endl;
    point::print();
}

circle::circle(double x_, double y_, double r_):point(x_, y_) {
    r = r_;
    area = acos(-1.0) * pow(r, 2);
}

circle::~circle() {}

void circle::print() {
    cout << "area : " << fixed << setprecision(2) << area << endl;
    point::print();
}

todo::todo(double x_, double y_, double dx_, double dy_, double r_)
    :vector(x_, y_, dx_, dy_), circle(x_, y_, r_) {}

todo::~todo() {}

void todo::print() {
    double volume = 2 * length * r + area;
    cout << "volume : " << fixed << setprecision(2) << volume << endl;
    vector::print();
    circle::print();
}
