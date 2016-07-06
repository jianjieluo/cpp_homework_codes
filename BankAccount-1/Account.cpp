#include "Account.h"
#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
using namespace std;

int Account::_total_account = 0;

int Account::get_total_account() {
    return _total_account;
}

Account::Account() {
    _id = _balance = 0;
    _valid = false;
    _total_account++;
}

Account::~Account() {_total_account--;}

int Account::id() const {
    return _id;
}

double Account::balance() const {
    return _balance;
}

bool Account::valid() const {
    return _valid;
}

string Account::profile() const {
    char a[300];
    memset(a, 0, sizeof(a));
    snprintf(a, sizeof(a), "ID:%d\nBALANCE:%.6lf\nVALID:N\n", id(), balance());
    string temp(a);
    return temp;
}

void Account::reset() {
    _balance = 0;
    _valid = false;
}

bool Account::deposit(const double &num) {
    if (_valid == false) return false;
    _balance += num;
    return true;
}

bool Account::draw(const double &num) {
    if (_valid == false) return false;
    if (_balance - num < 0.01) return false;
    _balance -= num;
    return true;
}

