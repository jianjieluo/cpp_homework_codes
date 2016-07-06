#include <iostream>
#include "PersonalAccount.h"
#include <string>
#include <cstdio>
#include <cstring>
using namespace std;

int PersonalAccount::_total_per_account = 0;
int PersonalAccount::_acc_id_ptr = 12010000;

int PersonalAccount::get_total_per_account() {
    return _total_per_account;
}

PersonalAccount::PersonalAccount() {
    _id = _acc_id_ptr++;
    _balance = 10;
    _valid = true;
    _total_per_account++;
}

PersonalAccount::~PersonalAccount() {
    _total_per_account--;
}

string PersonalAccount::profile() const {
    char a[300];
    memset(a, 0, sizeof(a));
    snprintf(a, sizeof(a), "ID:%d\nBALANCE:%.6lf\nVALID:Y\nTYPE:PERSONAL\n",
    id(), balance());
    string temp(a);
    return temp;
}

void PersonalAccount::reset() {
    _balance = 10;
    _valid = true;
}

