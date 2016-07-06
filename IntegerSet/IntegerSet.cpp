#include "IntegerSet.h"
#include <iostream>
using namespace std;

IntegerSet::IntegerSet(int s[], int l) {
    emptySet();
    for (int i = 0; i < l; i++)
	insertElement(s[i]);
}

IntegerSet IntegerSet::unionOfSets(const IntegerSet& s) {
    IntegerSet temp;
    for (int i = 0; i < 101; i++)
    temp.set[i] = set[i] | s.set[i];
    return temp;
}

IntegerSet IntegerSet::intersectionOfSets(const IntegerSet& s) {
    IntegerSet temp;
    for (int i = 0; i < 101; i++)
    temp.set[i] = set[i] & s.set[i];
    return temp;
}

void IntegerSet::emptySet() {
    for (int i = 0; i < 101; i++)
    set[i] = 0;
}

void IntegerSet::insertElement(int element) {
    if (validEntry(element)) {
        set[element] = 1;
    } else {
        cout << "Invalid insert attempted!" << endl;
    }
}

void IntegerSet::deleteElement(int element) {
    if (validEntry(element)) set[element] = 0;
    else cout << "Invalid delete attempted" << endl;
}

bool IntegerSet::isEqualTo(const IntegerSet& s) const {
    bool judge = true;
    for (int i = 0; i < 101; i++) {
        if (set[i] != s.set[i]) {
            judge = false;
            break;
        }
    }
    return judge;
}

