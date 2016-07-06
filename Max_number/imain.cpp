#include <iostream>
#include <string>
using namespace std;

void swap(string &a, string &b) {
    string temp = a;
    a = b;
    b = temp;
}

int main() {
    int n;
    cin >> n;
    string *a = new string[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    string *b = new string[n];
    for (int i = 0; i < n; i++) {
        b[i] = a[i];
    }
    for (int i = 0; i < n; i++) {
        if (a[i].length() == 1) {
            string temp = a[i];
            a[i] = a[i] + temp + temp;
        }
        if (a[i].length() == 2) {
            a[i].push_back((a[i])[1]);
        }
    }
    for (int i = 0; i < n - 1; i++) {
        for (int j = n - 1; j > i; j--) {
            if (a[j - 1] < a[j]) {
                swap(a[j - 1], a[j]);
                swap(b[j - 1], b[j]);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        cout << b[i];
    }
    cout << endl;
    delete []a;
    delete []b;
    a = b = NULL;
}

