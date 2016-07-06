#include <iostream>
#include "Datetime.h"
#include "Date.h"
#include "Time.h"
using namespace std;

Datetime::Datetime() {}

Datetime::Datetime(int year_, int month_, int day_, int hour_, int minute_,
int second_):Time(hour_, minute_, second_), Date(year_, month_, day_) {}

Datetime::~Datetime() {
    cout << "Destructor: " << toString() << endl;
}

string Datetime::toString() {
    string str = "";
    str += Date::toString();
    str += " ";
    str += Time::toString();
    return str;
}

Datetime Datetime::after(int seconds) {
    Datetime temp = (*this);
    while (seconds--) {
        ++temp;
    }
    return temp;
}

Datetime& Datetime::operator= (const Datetime& oth) {
    Date::setYear(oth.Date::getYear());
    Date::setMonth(oth.Date::getMonth());
    Date::setDay(oth.Date::getDay());
    Time::setHour(oth.Time::getHour());
    Time::setMinute(oth.Time::getMinute());
    Time::setSecond(oth.Time::getSecond());
    return (*this);
}

bool Datetime::operator< (const Datetime& oth) {
    Date d1(Date::getYear(), Date::getMonth(), Date::getDay());
    Date d2(oth.Date::getYear(), oth.Date::getMonth(), oth.Date::getDay());
    Time t1(Time::getHour(), Time::getMinute(), Time::getSecond());
    Time t2(oth.Time::getHour(), oth.Time::getMinute(), oth.Time::getSecond());
    if (d1 < d2) {
        return true;
    } else if (d1 > d2) {
        return false;
    } else {
        if (t1.getHour() < t2.getHour()) return true;
        if (t1.getHour() > t2.getHour()) return false;
        if (t1.getMinute() < t2.getMinute()) return true;
        if (t1.getMinute() > t2.getMinute()) return false;
        return (t1.getSecond() < t2.getSecond());
    }
}

bool Datetime::operator> (const Datetime& oth) {
    Date d1(Date::getYear(), Date::getMonth(), Date::getDay());
    Date d2(oth.Date::getYear(), oth.Date::getMonth(), oth.Date::getDay());
    Time t1(Time::getHour(), Time::getMinute(), Time::getSecond());
    Time t2(oth.Time::getHour(), oth.Time::getMinute(), oth.Time::getSecond());
    if (d1 > d2) {
        return true;
    } else if (d1 < d2) {
        return false;
    } else {
        if (t1.getHour() > t2.getHour()) return true;
        if (t1.getHour() < t2.getHour()) return false;
        if (t1.getMinute() > t2.getMinute()) return true;
        if (t1.getMinute() < t2.getMinute()) return false;
        return (t1.getSecond() > t2.getSecond());
    }
}

bool Datetime::operator== (const Datetime& oth) {
    Date d1(Date::getYear(), Date::getMonth(), Date::getDay());
    Date d2(oth.Date::getYear(), oth.Date::getMonth(), oth.Date::getDay());
    Time t1(Time::getHour(), Time::getMinute(), Time::getSecond());
    Time t2(oth.Time::getHour(), oth.Time::getMinute(), oth.Time::getSecond());
    if (d1 == d2 && t1.getHour() == t2.getHour() &&
    t1.getMinute() == t2.getMinute() && t1.getSecond() == t2.getSecond()) {
        return true;
    } else {
        return false;
    }
}

bool Datetime::operator!= (const Datetime& oth) {
    return !((*this) == oth);
}

Datetime& Datetime::operator++ () {
    Time::increment();
    if (getHour() == 0 && getMinute() == 0 && getSecond() == 0)
        Date::increment();
    return (*this);
}

Datetime Datetime::operator++ (int i) {
    Datetime before = (*this);
    ++(*this);
    return before;
}

