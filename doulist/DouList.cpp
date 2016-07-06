#include "DouList.h"
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int DouList::_error_sign = -1;

DouList::DouList() {
    m_head = NULL;
    m_tail = NULL;
}

DouList::DouList(const DouList &src) {
    m_head = m_tail = NULL;
    (*this) = src;
}

string change(int i) {
    stringstream ss;
    ss << i;
    return ss.str();
}

string DouList::to_str() const {
    string temp = "[";
    if (empty()) {
        temp += "]";
    } else {
        temp += change(m_head -> elem);
        DouListNode* ptr = m_head -> next;
        while (ptr != NULL) {
            temp += ", ";
            temp += change(ptr -> elem);
            ptr = ptr -> next;
        }
        temp += "]";
    }
    return temp;
}

DouList::~DouList() {
    clear();
}

void DouList::clear() {
    while (m_head != NULL) {
        DouListNode* temp = m_head;
        m_head = m_head -> next;
        delete temp;
    }
    m_tail = NULL;
}

bool DouList::empty() const {
    return(m_head == NULL);
}

int DouList::front() const {
    if (empty()) {
        return _error_sign;
    } else {
        return (m_head -> elem);
    }
}

int DouList::back() const {
    if (empty()) return _error_sign;
    else return (m_tail -> elem);
}

void DouList::push_front(const int &e) {
    if (empty()) m_head = m_tail = new DouListNode(e);
    else m_head = (m_head -> prev) = new DouListNode(e, 0, m_head);
}

void DouList::push_back(const int &e) {
    if (empty()) m_head = m_tail = new DouListNode(e);
    else m_tail = (m_tail -> next) = new DouListNode(e, m_tail, 0);
}

void DouList::pop_front() {
    if (!empty()) {
        DouListNode* temp = m_head;
        m_head = m_head -> next;
        delete temp;
        if (m_head == NULL) m_tail = NULL;
        else m_head -> prev = NULL;
    }
}

void DouList::pop_back() {
    if (!empty()) {
        DouListNode* temp = m_tail;
        m_tail = m_tail -> prev;
        delete temp;
        if (m_tail == NULL) m_head = NULL;
        else m_tail -> next = NULL;
    }
}

void DouList::operator= (const DouList &other) {
    clear();
    DouListNode* ptr = other.m_head;
    while (ptr != NULL) {
        push_back(ptr -> elem);
        ptr = ptr -> next;
    }
}

ostream& operator<< (ostream &out,
        const DouList &list) {
    out << list.to_str();
    return out;
}
