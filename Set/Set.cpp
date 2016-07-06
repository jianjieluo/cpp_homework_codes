#include "Set.hpp"

Set::Set() {
    size = 0;
}

Set::Set(int* m, int s) {
    size = 0;
    for (int i = 0; i < s; i++) {
        if (!(isInSet(m[i]))) {
            members[size++] = m[i];
        }
        if (size == MAX_MEMBERS) break;
    }
}

bool Set::append(int e) {
    bool judge = true;
    if (size == MAX_MEMBERS) judge = false;
    if (judge) {
        for (int i = 0; i < size; i++) {
            if (members[i] == e) judge = false;
        }
    }
    if (judge) members[size++] = e;
    return judge;
}

bool Set::remove(int e) {
    bool judge = true;
    int place = size;
    for (int i = 0; i < size; i++) {
        if (members[i] == e) place = i;
        break;
    }
    if (place == size) judge = false;
    if (judge) {
      if (size > 1) {
        for (int i = place; i < size - 1; i++)
            members[i] = members[i + 1];
        size--;
      } else {
        size = 0;
      }
    }
    return judge;
}

bool Set::isEmptySet() {
    if (size == 0) return true;
    else return false;
}

int* Set::getMembers() {
    return members;
}

int Set::getSize() {
    return size;
}

bool Set::isInSet(int e) {
    bool judge = false;
    for (int i = 0; i < size; i++) {
        if (members[i] == e) {
            judge = true;
            break;
        }
    }
    return judge;
}
