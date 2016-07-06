#include <iostream>
#include <cstdio>
#include <map>
#include <set>
#include <utility>
using namespace std;

int main(void) {
    int n;
    cin >> n;
    map<string, set<string> > qqtoip;
    map<string, set<string> > iptoqq;
    while (n--) {
        string qq, ip;
        cin >> qq >> ip;
        qqtoip[qq].insert(ip);
        iptoqq[ip].insert(qq);
    }
    string fqq, fip;
    cin >> fip >> fqq;
    if (iptoqq.find(fip) == iptoqq.end()) {
        cout << "no qq" << endl;
    } else {
        string a;
        a += fip;
        a += " ==> [ ";
        for (set<string>::iterator i = iptoqq[fip].begin(); i != iptoqq[fip].end(); ++i) {
            a += *i;
            a += " ";
        }
        a += "]";
        cout << a << endl;
    }
    if (qqtoip.find(fqq) == qqtoip.end()) {
        cout << "no ip" << endl;
    } else {
        string a;
        a += fqq;
        a += " ==> [ ";
        for (set<string>::iterator i = qqtoip[fqq].begin(); i != qqtoip[fqq].end(); ++i) {
            a += *i;
            a += " ";
        }
        a += "]";
        cout << a << endl;
    }
    return 0;
}
