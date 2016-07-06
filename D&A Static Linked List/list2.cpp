#include <algorithm>
#include <string>
#include <sstream>
#include "list.hpp"
using namespace std;

list::list() {
    _size = 0;
    head = nullpointer;
    empty_head = 0;
    for (int i = 0; i < MAX_STORAGE; i++)
        storage[i].next = i + 1;
    storage[MAX_STORAGE - 1].next = 0;
}

list::list(const list& another) {
    (*this) = another;
}

list& list::operator= (const list& another) {
    _size = another.size();
    head = another.head;
    empty_head = another.empty_head;
    for (int i = 0; i < MAX_STORAGE; i++) {
        storage[i].data = another.storage[i].data;
        storage[i].next = another.storage[i].next;
    }
}

list::~list() {
    clear();
}

bool list::empty(void) const {
    if (_size == 0) return true;
    else return false;
}

list::size_type list::size(void) const {
    return _size;
}


string change(int integer) {
    stringstream ss;
    ss << integer;
    return ss.str();
}

string list::toString(void) const {
    string temp = "";
    pointer ptr = head;
    while (ptr != nullpointer) {
        temp += change(storage[ptr].data);
        temp += "->";
        ptr = storage[ptr].next;
    }
    temp += "NULL";
    return temp;
}

void list::insert(int position, const int& data) {
    size_type p = static_cast<size_type>(position);
    if (p > _size) {
        return;
    } else {
        if (empty()) {
            head = empty_head;
            empty_head = storage[empty_head].next;
            _size++;
            storage[head].data = data;
            storage[head].next = nullpointer;
        } else {
            if (position == 0) {
                pointer ptr = head;
                head = empty_head;
                empty_head = storage[empty_head].next;
                _size++;
                storage[head].data = data;
                storage[head].next = ptr;
            } else {
                pointer ptr = head;
                while (--position) {
                    ptr = storage[ptr].next;
                }
                pointer temp = empty_head;
                empty_head = storage[empty_head].next;
                _size++;
                storage[temp].data = data;
                storage[temp].next = storage[ptr].next;
                storage[ptr].next = temp;
            }
        }
    }
}

void list::erase(int position) {
    size_type p = static_cast<size_type>(position);
    if (p >= _size) {
        return;
    } else {
        pointer ptr = head;
        if (position != 0) {
            while (--position) {
                ptr = storage[ptr].next;
            }
            pointer temp = storage[ptr].next;
            storage[ptr].next = storage[temp].next;
            storage[temp].next = empty_head;
            storage[temp].data = 0;
            empty_head = temp;
            _size--;
        } else {
            head = storage[head].next;
            storage[ptr].next = empty_head;
            empty_head = ptr;
            storage[empty_head].data = 0;
            _size--;
        }
    }
}

void list::clear() {
    for (int i = 0; i < MAX_STORAGE; i++) {
        storage[i].data = 0;
        storage[i].next = i + 1;
    }
    storage[MAX_STORAGE - 1].next = 0;
    head = nullpointer;
    empty_head = 0;
    _size = 0;
}

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

list& list::sort(void) {
    if (_size <= 1) return (*this);
    data_type* a = new data_type[_size];
    pointer ptr = head;
    int i = 0;
    while (ptr != nullpointer) {
        a[i++] = storage[ptr].data;
        ptr = storage[ptr].next;
    }
    for (size_type i = 0; i < _size - 1; i++) {
        for (size_type j = _size - 1; j > i; j--) {
            if (a[j - 1] > a[j]) swap(a[j - 1], a[j]);
        }
    }
    ptr = head;
    i = 0;
    while (ptr != nullpointer) {
        storage[ptr].data = a[i++];
        ptr = storage[ptr].next;
    }
    delete []a;
    return (*this);
}
