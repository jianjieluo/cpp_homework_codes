#ifndef DATE_H_
#define DATE_H_
#include <iostream>
#include <string>
using namespace std;

class Date {
    int year;
    int month;
    int day;
    public:
    static int a[12];
    Date();
    Date(int _year, int _month, int _day);
    ~Date();
    void setDay(int _day);
    void setMonth(int _month);
    void setYear(int _year);
    bool isRun();
    string toString() const;
    bool isValid();
    Date after(int n);
    bool operator <(const Date& othdate);
    bool operator >(const Date& othdate);
    Date& operator =(const Date& othdate);
    bool operator ==(const Date& othdate);
    bool operator !=(const Date& othdate);
    int& operator[](int i);
    Date& operator ++();
    Date operator ++(int);
    friend istream& operator >>(istream&, Date& othdate);
    friend ostream& operator <<(ostream&, const Date& othdate);
};
#endif

