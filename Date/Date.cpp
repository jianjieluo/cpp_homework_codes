#include <string>
#include <iostream>
#include <sstream>
#include "Date.h"
using namespace std;

int Date::a[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

Date::Date() {
    year = 0;
    month = 0;
    day = 0;
}

Date::Date(int _year, int _month, int _day) {
    year = _year;
    month = _month;
    day = _day;
}

Date::~Date() {
    cout << "Destructor: " << toString() << endl;
}

void Date::setDay(int _day) {
    day = _day;
}

void Date::setMonth(int _month) {
    month = _month;
}

void Date::setYear(int _year) {
    year = _year;
}

string change(int i) {
    stringstream ss;
    ss << i;
    return ss.str();
}

string Date::toString() const {
    string str = "";
    str += "[";
    str += change(year);
    str += "-";
    str += change(month);
    str += "-";
    str += change(day);
    str += "]";
    return str;
}

bool Date::isRun() {
    bool judge = true;
    if (year % 100) {
    if (year % 4) judge = false;
    } else {
    if (year % 400) judge = false;
    }
    return judge;
}

bool Date::isValid() {
    bool judge = true;
    if (day < 1) judge = false;
    if (month < 1 || month > 12) judge = false;
    if (judge) {
        if (!isRun()) {
            if (a[month - 1] < day) judge = false;
        } else {
            if (month == 2) {
                if (day > 29) judge = false;
            } else {
                if (a[month - 1] < day) judge = false;
            }
        }
    }
    return judge;
}

Date Date::after(int n) {
    Date newDate = *this;
    while (n--) {
        ++newDate;
    }
    return newDate;
}

bool Date::operator <(const Date& othdate) {
    if (year < othdate.year) {
        return true;
    } else if (year > othdate.year) {
        return false;
    } else {
        if (month < othdate.month) {
            return true;
        } else if (month > othdate.month) {
            return false;
        } else {
            if (day < othdate.day) {
                return true;
            } else {
                return false;
            }
        }
    }
}

bool Date::operator >(const Date& othdate) {
    if (year > othdate.year) {
        return true;
    } else if (year < othdate.year) {
        return false;
    } else {
        if (month > othdate.month) {
            return true;
        } else if (month < othdate.month) {
            return false;
        } else {
            if (day > othdate.day) {
                return true;
            } else {
                return false;
            }
        }
    }
}

Date& Date::operator =(const Date& othdate) {
    year = othdate.year;
    month = othdate.month;
    day = othdate.day;
    return *this;
}

bool Date::operator ==(const Date& othdate) {
    bool judge = true;
    if (year != othdate.year) judge = false;
    if (month != othdate.month) judge = false;
    if (day != othdate.day) judge = false;
    return judge;
}

bool Date::operator !=(const Date& othdate) {
    return (!(*this == othdate));
}

Date& Date::operator ++() {
    if (isRun()) a[1] = 29;
    day += 1;
    if (day > a[month - 1]) {
        day -= a[month++ - 1];
    }
    if (month > 12) {
        year += 1;
        month /= 12;
    }
    if (!isRun()) a[1] = 28;
    return *this;
}

Date Date::operator ++(int i) {
    Date before = *this;
    if (isRun()) a[1] = 29;
    day += 1;
    if (day > a[month - 1]) {
        day -= a[month++ - 1];
    }
    if (month > 12) {
        year += 1;
        month /= 12;
    }
    if (!isRun()) a[1] = 28;
    return before;
}

int& Date::operator[](int i) {
    switch (i) {
        case(0): return year;
        break;
        case(1): return month;
        break;
        case(2): return day;
        break;
    }
}

ostream& operator<< (ostream& out, const Date& othdate) {
    out << othdate.toString() << endl;
    return out;
}

istream& operator>> (istream& in, Date& othdate) {
    in >> othdate.year >> othdate.month >> othdate.day;
    return in;
}
