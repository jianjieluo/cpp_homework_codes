#ifndef CMP_H_
#define CMP_H_
#include <string>
#include <cstring>
using namespace std;

template <typename T>
bool cmp(T a, T b) {
    if (a == b) return true;
    else return false;
}

template <typename T>
bool cmp(T* a, T* b) {
    if (*a == *b) return true;
    else return false;
}

bool cmp(string a, string b) {
    if (a == b) return true;
    else return false;
}

bool cmp(char* a, char* b) {
    int x = strlen(a);
    int y = strlen(b);
    int length = (x > y) ? y : x;
    if (strncmp(a, b, length) == 0) return true;
    else return false;
}
#endif

