#ifndef STRING_H_
#define STRING_H_
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;

class String {
    public:
        String();
        explicit String(const char *src);
        String(const String &src);

        ~String();

        String& operator =(const String& src);
        const char* c_str() const;
        inline char& operator[](int i);

        friend ostream& operator <<(ostream& os, const String& src);

    private:
        char *_buff;
        int _size;
};

String::String() {
    _buff = NULL;
    _size = 0;
}

String::String(const char* src) {
    _size = strlen(src) + 1;
    _buff = new char[_size];
    strncpy(_buff, src, _size);
}

String::String(const String &src) {
    _size = src._size;
    _buff = new char[_size];
    strncpy(_buff, src._buff, _size);
}

String::~String() {
    delete []_buff;
    _size = 0;
}

String& String::operator= (const String& src) {
    if (_buff != NULL) delete []_buff;
    _size = src._size;
    _buff = new char[_size];
    strncpy(_buff, src._buff, _size);
}

const char* String::c_str() const {
    return _buff;
}

char& String::operator[] (int i) {
    return _buff[i];
}

ostream& operator<< (ostream& os, const String& src) {
    os << src.c_str();
    return os;
}
#endif

