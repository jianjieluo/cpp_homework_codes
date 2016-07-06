#include<iostream>
#include"counter1.h"
#include"counter2.h"
using namespace std;
int main() {
    counter2::set(3);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        counter1::count();
    }
    for (int i = 0; i < m; i++) {
        counter2::count();
    }
    counter1 x;
    x();
    cout << counter1::counter << endl;
    cout << counter2::counter << endl;
}
 
