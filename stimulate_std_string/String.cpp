#include <string>
#include <cstring>
#include <iostream>
#include "String.h"

char String::_error_sign = '\0';
String::String() {
    _buff = 0;
    _length = 0;
    _size = 0;
}

String::String(const char *src) {
    _length = _size = 0;
    _buff = 0;
    (*this) = src;
}

String::String(const String &src) {
    _length = _size = 0;
    _buff = 0;
    (*this) = src;
}

String::~String() {
    clear();
}

void String::assign(const char *src) {
    String temp(src);
    (*this) = temp;
}

void String::append(const char &other) {
    if (_length == 0) {
        clear();
        _length = 1;
        _size = 2;
        _buff = new char[_size];
        _buff[0] = other;
        _buff[1] = '\0';
    } else {
        String temp = (*this);
        clear();
        _length = temp._length + 1;
        _size = temp._size + 1;
        _buff = new char[_size];
        strncpy(_buff, temp._buff, temp._size);
        _buff[temp._length] = other;
        _buff[_length] = '\0';
    }
}

void String::clear() {
    if (_buff) {
        delete []_buff;
        _buff = 0;
    }
    _length = _size = 0;
}

int String::compare(const String &other) const {
    int size = (_size > other._size) ? other._size : _size;
    int judge = strncmp(_buff, other._buff, size);
    if (judge > 0) return 1;
    if (judge < 0) return -1;
    return judge;
}

const char* String::c_str() const {
    if (!this->empty()) return _buff;
    else return "";
}

bool String::empty() const {
    if (_length == 0) return true;
    else return false;
}

int String::find(const String &other, int pos) const {
    std::string a(_buff);
    int judge = a.find(other._buff, pos);
    if (judge < 0) return _length;
    else return judge;
}

int String::length() const {
    return _length;
}

String String::substr(const int &pos, const int &count) const {
    char* temp = new char[count + 1];
    int k = pos + count;
    for (int i = pos, j = 0; i < k; i++, j++)
        temp[j] = _buff[i];
    temp[count] = '\0';
    String t(temp);
    delete []temp;
    return t;
}

char& String::operator[] (const int &index) {
    return _buff[index];
}

void String::operator= (const String &other) {
    clear();
    if (other._buff != 0) {
        _length = other._length;
        _size = other._size;
        _buff = new char[_size];
        strncpy(_buff, other._buff, _size);
    } else {
        _length = _size = 0;
        _buff = 0;
    }
}

void String::operator= (const char *src) {
    clear();
    if (src != 0) {
        _length = strlen(src);
        _size = _length + 1;
        _buff = new char[_size]();
        strncpy(_buff, src, _size);
    } else {
        _length = _size = 0;
        _buff = 0;
    }
}

String String::operator+(const String &other) const {
    String temp;
    temp._length =  _length + other._length;
    temp._size = _size + other._size;
    temp._buff = new char[temp._size]();
    strncpy(temp._buff, _buff, _size);
    strncat(temp._buff, other._buff, other._size);
    return temp;
}

bool String::operator< (const String &other) const {
    int judge = compare(other);
    if (judge < 0) return true;
    else return false;
}

bool String::operator<= (const String &other) const {
    int judge = compare(other);
    if (judge > 0) return false;
    else return true;
}

bool String::operator> (const String &other) const {
    int judge = compare(other);
    if (judge > 0) return true;
    else return false;
}

bool String::operator>= (const String &other) const {
    int judge = compare(other);
    if (judge < 0) return false;
    else return true;
}

bool String::operator== (const String &other) const {
    int judge = compare(other);
    if (judge == 0) return true;
    else return false;
}

bool String::operator!= (const String &other) const {
    return (!((*this) == other));
}

std::ostream& operator<< (std::ostream& out, const String &str) {
    out << str.c_str();
    return out;
}

