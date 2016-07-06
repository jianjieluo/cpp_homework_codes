#ifndef BITSET_H_
#define BITSET_H_
#include <iostream>
#include <cstring>
using namespace std;

class Bitset {
    private:
        int n;
        bool a[1100];
    public:
        Bitset() {
            memset(a, 0, sizeof(a));
        }
        void set_size(int x) {
            n = x;
         }
        void set(int x);
        void print();
};

void Bitset::set(int x) {
    a[x] = 1;
}

void Bitset::print() {
    for (int i = 0; i < n; i++)
        cout << a[i];
    cout << endl;
}

#endif

