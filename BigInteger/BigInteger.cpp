#include <iostream>
#include <string>
#include "BigInteger.h"
using namespace std;

BigInteger::BigInteger() {
    size_ = 0;
    data_ = NULL;
}

// BigInteger can't use char to store ,for it can't deal with the jingwei !!!
BigInteger::BigInteger(const string& number) {
    size_ = number.size();
    data_ = new int[size_];
    for (int i = 0, j = size_ - 1; i < size_; i++, j--)
        data_[i] = number[j] - '0';
}

BigInteger::BigInteger(const BigInteger& other) {
    size_ = other.size_;
    data_ = new int[other.size_];
    for (int i = 0; i < other.size_; i++)
        data_[i] = other.data_[i];
}

BigInteger operator+ (const BigInteger& left, const BigInteger& right) {
    BigInteger temp;
    if (left.size_ > right.size_) {
        temp.size_ = left.size_ + 1;
        temp.data_ = new int[temp.size_];
        temp.data_[temp.size_ - 1] = 0;
        for (int i = 0; i < right.size_; i++)
            temp.data_[i] = left.data_[i] + right.data_[i];
        for (int i = right.size_; i < left.size_; i++)
            temp.data_[i] = left.data_[i];
    } else {
        temp.size_ = right.size_ + 1;
        temp.data_ = new int[temp.size_];
        temp.data_[temp.size_ - 1] = 0;
        for (int i = 0; i < left.size_; i++)
            temp.data_[i] = left.data_[i] + right.data_[i];
        for (int i = left.size_; i < right.size_; i++)
            temp.data_[i] = right.data_[i];
    }
    // jingwei chuli
    int tem = temp.size_ - 1;
    for (int i = 0; i < tem; i++) {
        if (temp.data_[i] > 9) {
            temp.data_[i + 1] += 1;  // (temp.data_[i] / 9);
            temp.data_[i] %= 10;
        }
    }
    while (temp.data_[temp.size_ - 1] == 0) {
        if (temp.size_ == 1) break;
        temp.size_--;
    }
    return temp;
}

BigInteger operator- (const BigInteger& left, const BigInteger& right) {
    BigInteger temp;
    temp.size_ = left.size_;
    temp.data_ = new int[temp.size_];
    for (int i = 0; i < right.size_; i++)
        temp.data_[i] = left.data_[i] - right.data_[i];
    for (int i = right.size_; i < left.size_; i++)
        temp.data_[i] = left.data_[i];
    for (int i = 0; i < temp.size_; i++) {
        if (temp.data_[i] < 0) {
            temp.data_[i] += 10;
            temp.data_[i + 1]--;
        }
    }
    while (temp.data_[temp.size_ - 1] == 0) {
        if (temp.size_ == 1) break;
        temp.size_--;
    }
    return temp;
}

ostream& operator<< (ostream& out, const BigInteger& Bint) {
    for (int i = Bint.size_ - 1; i >= 0; i--)
        out << Bint.data_[i];
    return out;
}

BigInteger::~BigInteger() {
    delete []data_;
}

