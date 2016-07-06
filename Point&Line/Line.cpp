#include <sstream>
#include "Point.h"
#include "Line.h"
#include <string>
#include <cmath>
#include <cstdlib>
using namespace std;

string lchange(int i) {
    std::stringstream ss;
    ss << i;
    return ss.str();
}

Line::Line() {
    a = 0;
    b = 0;
    c = 0;
}

Line::Line(double a1, double b1, double c1) {
    a = a1;
    b = b1;
    c = c1;
}

void Line::reset(const double &a1, const double &b1, const double &c1) {
    a = a1;
    b = b1;
    c = c1;
}

string Line::display() {
    string str = "";
    if (a != 0) {
    str += lchange(a);
    str += "x";
    }
    if (a != 0) {
        if (b > 0) {
            str += "+";
            str += lchange(b);
	    str += "y";
        } else if (b < 0) {
            str += lchange(b);
	    str += "y";
        }
    } else {
        str += lchange(b);
        str += "y";
    }
    if (b != 0) {
        if (c > 0) {
            str += "+";
            str += lchange(c);
        } else if (c < 0) {
            str += lchange(c);
        }
    } else {
        str += lchange(c);
    }
    str += "=0";
    return str;
}

double dist_LP(const Line &l, const Point &p) {
    double temp1 = abs(l.a * p.x + l.b * p.y + l.c);
    double temp2 = sqrt(pow(l.a, 2) + pow(l.b, 2));
    return temp1 / temp2;
}

double dist_LL(const Line &l1, const Line &l2) {
    if (l1.a / l1.b != l2.a / l2.b) {
        return -1;
    } else {
	double r = l1.a / l2.a;
	double c1 = l1.c / r;
        double temp1 = abs(c1 - l2.c);
        double temp2 = sqrt(pow(l2.a, 2) + pow(l2.b, 2));
        return temp1 / temp2;
    }
}

