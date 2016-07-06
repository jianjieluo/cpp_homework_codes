#include <iostream>
#include <stdio.h>
#include <cstring>
#include <sys/time.h>
#include <vector>
using namespace std;

static long long int maxMem = 8 * 1024 * 1024 - 50;
static time_t time_begin, time_now;
static vector<long long int> v;

typedef bool (*check) ();
typedef void (*func) (check, int, int);

long getCurrentTime() {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return tv.tv_sec * 1000 + tv.tv_usec / 1000;
}

#define TIC() time_begin = getCurrentTime();
#define TOC() time_now = getCurrentTime();
#define MEM_CHECK() (v.size()*sizeof(long long int) > maxMem ? 1 : 0)

void display(check c, int a, int b) {
    cout << "Input is " << a << " and " << b << ".\n";
}

void add(check c, int a, int b) {
    cout << a << " + " << b << " = " << a + b << ".\n";
}

// Infinite loop inside.
void inf(check c, int a, int b) {
    TIC();
    while (1) {
        TOC();
        if (c()) {
            cout << "Infinite break.\n";
            time_now = time_begin = 0;
            break;
        }
    }
}

// Find prime number.
void find(check c, int a, int b) {
    int pos = 1, num = 3;
    TIC();
    while (1) {
        for (int i = 2; i < num; i++)
            if (num % i == 0) break;
            else if (i == num - 1) pos++;
        TOC();
        if (c()) {
            if (num > 20000) cout << "Find succeed!\n";
            else cout << "Find nothing.\n";
            time_now = time_begin = 0;
            break;
        }
        num++;
    }
}

// Allocate memory for the program.
void alloc(check c, int a, int b) {
    while (1) {
        long long int ch = 999999999;
        v.push_back(ch);
        if (c()) {
            if (MEM_CHECK()) cout << "Memory has been full.\n";
            else cout << "Memory hasn't been full.\n";
            v.clear();
            break;
        }
    }
}

