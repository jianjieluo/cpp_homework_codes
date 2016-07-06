#include "list.hpp"
#include <sstream>
#include <iostream>
#include <string>

void swap(int*, int*);
std::string change(int i);

list::list() {
    head = NULL;
    _size = 0;
}

list::list(const list& l) {
    if (l.head == NULL) {
        head = NULL;
        _size = 0;
    } else {
        node* ptr = l.head -> next;
        _size = 1;
        head = new node(l.head -> data);
        for (int i = 1; i < l._size; i++) {
            insert(i, ptr -> data);
            ptr = ptr -> next;
        }
    }
    _size = l._size;
}  // still have question

list& list::operator =(const list& l) {
    clear();
    if (l.head == NULL) {
        head = NULL;
        _size = 0;
    } else {
        node* ptr = l.head -> next;
        _size = 1;
        head = new node(l.head -> data);
        for (int i = 1; i < l._size; i++) {
            insert(i, ptr -> data);
            ptr = ptr -> next;
        }
        _size = l._size;
    }
    return *this;
}

list::~list() {
    clear();
}

bool list::empty(void) const {
    if (head != NULL) return false;
    else return true;
}

int list::size(void) const {
    return _size;
}

std::string list::toString(void) const {
    std::string str = "";
    node *ptr = head;
    while (ptr != NULL) {
        str += change(ptr -> data);
        str += "->";
        ptr = ptr -> next;
    }
    str += "NULL";
    return str;
}

std::string change(int i) {
    std::stringstream ss;
    ss << i;
    return ss.str();
}

void list::insert(int position, const int& data) {
    if (position > _size) {
        return;
    } else {
        node *current = new node(data);
        if (position == 0) {
            current -> next = head;
            head = current;
            _size++;
        } else {
            node *ptr = head;
            while (--position) {
                ptr = ptr -> next;
            }
            current -> next = ptr -> next;
            ptr -> next = current;
            _size++;
        }
    }
}

void list::erase(int position) {
    if (position < _size) {
        if (position != 0) {
            node *ptr = head;
            while (--position) {
                ptr = ptr -> next;
            }
            node *temp = ptr -> next;
            ptr -> next = temp -> next;
            delete temp;
            _size--;
        } else {
            node *temp = head;
            head = head -> next;
            delete temp;
            _size--;
        }
    } else {
        return;
    }
}

list& list::sort(void) {
    int a[2000];
    node* ptr = head;
    int i = 0;
    while (ptr != NULL) {
        a[i++] = ptr -> data;
        ptr = ptr -> next;
    }
    for (int p = 0; p < _size - 1; p++) {
        for (int q = _size - 1; q > p; q--) {
            if (a[q - 1] > a[q]) swap(&a[q - 1], &a[q]);
        }
    }
    ptr = head;
    i = 0;
    while (ptr != NULL) {
         ptr -> data = a[i++];
         ptr = ptr -> next;
    }
    return *this;
}

void swap(int *a, int *b) {
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
