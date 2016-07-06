#ifndef BITSET_H
#define BITSET_H
#include<iostream>
template <int max>
class bitset {
    private:
        int a[2];
    public:
        bitset();
        void set(int pos);
        void reset(int pos);
        int count() const;
        bool test(int pos) const;
        bool any() const;
        bool none() const;
        bool all() const;
        bitset<max>& operator&= (const bitset<max>& oth);
        bitset<max>& operator|= (const bitset<max>& oth);
        bitset<max>& operator^= (const bitset<max>& oth);
        bitset<max>& operator= (const bitset<max>& oth);
        bitset<max>& operator <<= (int pos);
        bitset<max>& operator >>= (int pos);
        bitset<max> operator~() const;
        bitset<max> operator&(const bitset<max>& oth) const;
        bitset<max> operator|(const bitset<max>& oth) const;
        bitset<max> operator^(const bitset<max>& oth) const;
        bitset<max> operator<<(int pos) const;
        bitset<max> operator>>(int pos) const;
        bool operator== (const bitset<max>& oth) const;
        bool operator!= (const bitset<max>& oth) const;
        bool operator[] (int pos) const;
        friend std::ostream& operator << (std::ostream& os, const bitset<max>& s) {
            for (int i = 1; i >= 0; i--) {
                for (int j = 31; j >= 0; j--) {
                    if (s.a[i] & (1 << j)) os << 1;
                    else os << 0;
                }
            }
            return os;
        }
};

template <int max>
bitset<max>::bitset() {
    for (int i = 0; i < 2; ++i)
        a[i] = 0;
}

template <int max>
void bitset<max>::set(int pos) {
    int i = pos / 32;
    int j = pos % 32;
    a[i] = a[i] | (1 << j);
}

template <int max>
void bitset<max>::reset(int pos) {
    int i = pos / 32;
    int j = pos % 32;
    a[i] = a[i] & ~(1 << j);
}

template <int max>
int bitset<max>::count() const {
    int count = 0;
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 32; ++j) {
            if (a[i] & (1 << j))
                ++count;
        }
    }
    return count;
}

template <int max>
bool bitset<max>::test(int pos) const {
    int i = pos / 32;
    int j = pos % 32;
    int judge = a[i] & (1 << j);
    if (judge) return true;
    else return false;
}

template <int max>
bool bitset<max>::any() const {
    if (count() > 0) return true;
    else return false;
}

template <int max>
bool bitset<max>::none() const {
    if (count() == 0) return true;
    else return false;
}

template <int max>
bool bitset<max>::all() const {
    if (count() == max) return true;
    else return false;
}

template <int max>
bitset<max>& bitset<max>::operator&= (const bitset<max>& oth) {
    for (int i = 0; i < 2; ++i)
        a[i] &= oth.a[i];
    return(*this);
}

template <int max>
bitset<max>& bitset<max>::operator|= (const bitset<max>& oth) {
    for (int i = 0; i < 2; ++i)
        a[i] |= oth.a[i];
    return(*this);
}

template <int max>
bitset<max>& bitset<max>::operator^= (const bitset<max>& oth) {
    for (int i = 0; i < 2; ++i)
        a[i] ^= oth.a[i];
    return(*this);
}

template <int max>
bitset<max>& bitset<max>::operator= (const bitset<max>& oth) {
    for (int i = 0; i < 2; ++i)
        a[i] = oth.a[i];
    return(*this);
}

template <int max>
bitset<max>& bitset<max>::operator <<= (int pos) {
    while (pos--) {
        for (int i = 1; i >= 0; i--) {
            if (i == 0) {
                a[i] <<= 1;
                continue;
            }
            a[i] <<= 1;
            if (a[i-1] & (1 << 31)) a[i] |= 1;
            else a[i] &= ~1;
        }
    }
    return(*this);
}

template <int max>
bitset<max>& bitset<max>::operator>>= (int pos) {
    while (pos--) {
        for (int i = 0; i < 2; i++) {
            if (i == 1) {
                a[i] >>= 1;
                continue;
            }
            a[i] >>= 1;
            if (a[i + 1] & 1) a[i] |= 1 << 31;
            else a[i] &= ~(1 << 31);
        }
    }
    return(*this);
}

template <int max>
bitset<max> bitset<max>::operator~() const {
    bitset<max> temp;
    for (int i = 0; i < 2; i++) temp.a[i] = ~a[i];
    return temp;
}

template <int max>
bitset<max> bitset<max>::operator& (const bitset<max>& oth) const {
    bitset<max> temp(*this);
    return temp &= oth;
}

template <int max>
bitset<max> bitset<max>::operator| (const bitset<max>& oth) const {
    bitset<max> temp(*this);
    return temp |= oth;
}

template <int max>
bitset<max> bitset<max>::operator^ (const bitset<max>& oth) const {
    bitset<max> temp(*this);
    return temp ^= oth;
}

template <int max>
bitset<max> bitset<max>::operator<< (int pos) const {
    bitset<max> temp(*this);
    return temp <<= pos;
}

template <int max>
bitset<max> bitset<max>::operator>> (int pos) const {
    bitset<max> temp(*this);
    return temp >>= pos;
}

template <int max>
bool bitset<max>::operator== (const bitset<max>& oth) const {
    bool judge = true;
    for (int i = 0; i < 2; ++i) {
        if (a[i] != oth.a[i]) judge = false;
    }
    return judge;
}

template <int max>
bool bitset<max>::operator!= (const bitset<max>& oth) const {
    return !((*this) == oth);
}

template <int max>
bool bitset<max>::operator[] (int pos) const {
    int i = pos / 32;
    int j = pos % 32;
    if (a[i] & (1 << j)) return true;
    else return false;
}
#endif

