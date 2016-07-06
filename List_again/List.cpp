#include <iostream>
#include <string>
#include <sstream>
#include "List.hpp"
using namespace std;

list::list() {
    head = NULL;
    tail = NULL;
    _size = 0;
}

list::list(const data_type datas[], int length) {
    head = NULL;
    tail = NULL;
    _size = 0;
    assign(datas, length);
}  // remember to reuse the code

list::list(const list& l) {
    head = NULL;
    tail = NULL;
    _size = 0;
    assign(l);  // think whether it should be "this"
}

list& list::operator= (const list& l) {
    this -> assign(l);
    return *this;
}

list::~list() {
    clear();
}

data_type& front() const {
    return head -> data;
}

data_type& back() const {
    return tail -> data;
}

void list::assign(const list& l) {
    clear();
    if (l.head == NULL) {
        head = NULL;
        tail = NULL;
        _size = 0;
    } else {
        head = new listNode(l.head -> data);
        _size = 1;
        listPointer ptr = l.head -> next;
        for (int i = 1; i < l._size; i++) {
            push_back(ptr -> data);
            ptr = ptr -> next;
        }
        _size = l._size;
        ptr = NULL;
    }
}

void list::assign(const data_type datas[], int length) {
    clear();
    if (datas == NULL) {
        head = NULL;
        tail = NULL;
        _size = 0;
    } else {
        head = new listNode(datas[0]);
        _size = 1;
        for (int i = 1; i < length; i++)
            push_back(datas[i]);
        _size = length;
    }
}

void list::push_front(const data_type& n) {
    listPointer ptr = new listNode(n, head, NULL);
    head -> prev = ptr;
    head = ptr;
    ptr = NULL;
    _size++;
}

void list::push_back(const data_type& n) {
    listPointer ptr = new listNode(n, NULL, tail);
    tail -> next = ptr;
    tail = ptr;
    ptr = NULL;
    _size++;
}

void list::pop_front(void) {
    listPointer ptr = head;
    head = head -> next;
    head -> prev = NULL;
    delete ptr;
    ptr = NULL;
    _size--;
}

void list::pop_back(void) {
    listPointer ptr = tail;
    tail = tail -> prev;
    tail -> next = NULL;
    delete ptr;
    ptr = NULL;
    _size--;
}

void list::insert(int position, const data_type& data) {
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

void list::clear() {
    listPointer temp = head;
    while (head != NULL) {
        temp = head;
        head = head -> next;
        delete temp;
    }
    temp = NULL;
    tail = NULL;
    _size = 0;
}

void list::split(int position, list* des1, list* dest2) {
    if (position > _size) {
        return;
    } else if (position == _size) {
        *des1 = (*this);
        dest2 -> head = dest2 -> tail = NULL;
        dest2 -> _size = 0;
    } else if (position == 0) {
        *dest2 = (*this);
        des1 -> head = des1 -> tail = NULL;
        des1 -> _size = 0;
    } else {
        data_type* a = new data_type[position];
        data_type* b = new data_type[_size - position];
        listPointer ptr = head;
        for (int i = 0; i < position; i++) {
            a[i] = ptr -> data;
            ptr = ptr -> next;
        }
        des1 -> assign(a, position);
        for (int i = position; i < _size; i++) {
            b[i] = ptr -> data;
            ptr = ptr -> next;
        }
        dest2 -> assign(b, _size - position);
        delete []a;
        delete []b;
        a = b = ptr = NULL;
    }
}

string change(int integer) {
    stringstream ss;
    ss << integer;
    return ss.str();
}

list& list::merge(const list& src1; const list& src2) {
    data_type* a = new data_type[src1._size + src2._size];
    listPointer ptr = src1.head;
    for (int i = 0; i < src1._size; i++) {
        a[i] = ptr -> data;
        ptr = ptr -> next;
    }
    ptr = src2.head;
    for (int i = src1._size, int temp = src1._szie + src2._size; i < temp; i++) {
        a[i] = ptr -> data;
        ptr = ptr -> next;
    }
    this -> assign(a, src1._szie + src2._size);
    delete []a;
    ptr = a = NULL;
    return *this;
}

string list::toString() const {
    listPointer ptr = head;
    string str = "";
    if (head == NULL) {
        str += "NULL";
        return str;
    }
    while (ptr != NULL) {
        if (ptr -> prev == NULL && ptr -> next == NULL) {
            str += "NULL<-";
            str += change(ptr -> data);
            str += "->NULL";
        }
        if (ptr -> prev == NULL && ptr -> next != NULL) {
            str += "NULL<-";
            str += change(ptr -> data);
        }
        if (ptr -> prev != NULL && ptr -> next != NULL) {
            str += "<->";
            str += change(ptr -> data);
            str += "<->";
        }
        if (ptr -> prev != NULL && ptr -> next == NULL) {
            str += change(ptr -> data);
            str += "->NULL";
        }
        ptr = ptr -> next;
    }
    return str;
}

list& list::remove_if(bool (*condition)(listPointer)) {
    listPointer ptr = head;
    while (ptr != NULL) {
        if (condition(ptr)) {
            listPointer temp = ptr;
            ptr -> prev -> next = ptr -> next;
            ptr -> next -> prev = ptr -> prev;
            ptr = ptr -> next;
            delete temp;
            temp = NULL;
        } else {
            ptr = ptr -> next;
        }
    }
    return (*this);
}

list& list::unique() {

}

list& list::operator+= (const list& l) {
    listPointer ptr = l.head;
    for (int i = 0; i < l._size; i++) {
        push_back(ptr -> data);
        ptr = ptr -> next;
    }
    ptr = NULL;
    return *this;
}

data_type& list::operator[] (int index) {
    listPointer ptr = at(index);
    return ptr -> data;
}

ostream& operator<< (ostream& os, const list& li) {
    os << li.toString() << endl;
    return os;
}
