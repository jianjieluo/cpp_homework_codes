#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include"permu.h"
using namespace std;
int main() {
    int n, m;
    cin >> n >> m;
    permu a(n);  // n是排列的长度。初始排列为0,1,2,...,n-1
    permu b = a;
    b = ++a;
    cout << b << endl;
    b = a++;
    cout << b << endl;
    for (int i = 0; i < m; i++) {
        --a;
    }
    b = a--;
    cout << a << endl;
    cout << b << endl;
}

