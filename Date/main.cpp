#include <iostream>
#include "Date.h"
 
using namespace std;
 
int main() {
    Date date1 = Date(2015, 3, 21);
    Date date2 = Date(2016, 2, 29);
    cout << date1.toString() << endl;
 
    cout << date1++ << endl;
    cout << date1 << endl;
 
    cout << ++date2 << endl;
    cout << date2 << endl;
 
    cout << "The year of Date1 is: " << date2[0] << endl;
    cout << "The month of Date1 is: " << date2[1] << endl;
    cout << "The day of Date1 is: " << date2[2] << endl;
    // assertion: 0 <= index <= 2.
    int day;
    cin >> day;
    date1.setDay(day);
    if (date1.isValid()) cout << "date1 is valid!\n";
    else cout << "date1 is invalid!\n";
 
    date1[2] = 12;
    if (date1.isValid()) {
        cout << date1;
    }
 
    cin >> date2;
    if (date2.isValid()) {
        if (date1 < date2) cout << "date1 is earlier than date2" << endl;
        else cout << "date1 is not earlier than date2" << endl;
 
        Date date3 = Date(date1);
        Date date4 = date2;
        cout << (date3 == date1) << endl;
        cout << (date3 != date4) << endl;
        cout << (date3 > date1) << endl;
 
        int years;
        cin >> years;
        cout << date2.after(years).toString() << endl;
    } else {
        cout << "date2 is invalid!\n";
    }
}
 
