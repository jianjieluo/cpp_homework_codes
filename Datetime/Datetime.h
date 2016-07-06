#ifndef DATETIME_H_
#define DATETIME_H_
#include "Date.h"
#include "Time.h"
using namespace std;

class Datetime:public Time, public Date {
    public:
        Datetime();
        Datetime(int, int, int, int, int, int);
        ~Datetime();
        string toString();
        Datetime after(int seconds);
        bool operator< (const Datetime& oth);
        bool operator> (const Datetime& oth);
        Datetime& operator= (const Datetime& oth);
        bool operator== (const Datetime& oth);
        bool operator!= (const Datetime& oth);
        Datetime& operator++ ();
        Datetime operator++ (int);
};
#endif
