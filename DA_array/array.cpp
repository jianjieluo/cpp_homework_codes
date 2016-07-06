#include "array.hpp"
typedef int* pointer;
typedef unsigned int size_t;
typedef int data_type;

void swap(int *a, int *b) {
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

array::array(size_t size) {
    _size = size;
    _data = new data_type[size];
}

array::~array() {
    delete []_data;
}

size_t array::max_size() {
    return _size;
}

data_type& array::at(const data_type& i) {
    return _data[i];
}

data_type& array::front() {
    return _data[0];
}

data_type& array::back() {
    return _data[_size - 1];
}

pointer array::data() {
    return _data;
}

void array::fill(const data_type& value) {
    for (size_t i = 0; i < _size; i++)
    _data[i] = value;
}

void array::resize(int newSize) {
    pointer p = new data_type[newSize];
    size_t n = (size_t) newSize;
    for (size_t i = 0; i < _size; i++)
        p[i] = _data[i];
    for (size_t i = _size; i < n; i++)
        p[i] = 0;
    delete []_data;
    _data = p;
    _size = n;
}

void array::sort(int from, int to) {
    for (int i = from; i < to - 1; i++) {
        for (int j = to - 1; j > i; j--) {
            if (_data[j - 1] > _data[j])
            swap(&_data[j], &_data[j - 1]);
        }
    }
}

