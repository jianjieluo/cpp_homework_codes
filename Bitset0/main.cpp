#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include"Bitset.h"
int main() {
    Bitset a;
    int n, m;
    std::cin >> n >> m;
    a.set_size(m);
    for (int i = 1; i <= n; i++) {
        int x;
        std::cin >> x;
        a.set(x);
    }
    a.print();
}
 
