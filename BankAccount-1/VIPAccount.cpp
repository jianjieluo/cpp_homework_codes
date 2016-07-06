#include <iostream>
#include "VIPAccount.h"
#include <cstdio>
#include <cstring>
using namespace std;

int VIPAccount::_total_vip_account = 0;
int VIPAccount::_acc_id_ptr = 12050000;
int VIPAccount::get_total_vip_account() {
    return _total_vip_account;
};

VIPAccount::VIPAccount() {
    _id = _acc_id_ptr++;
    _balance = 10;
    _valid = true;
    _loan = 0;
    _total_vip_account++;
}

VIPAccount::~VIPAccount() {
    _total_vip_account--;
}

void VIPAccount::reset() {
    _balance = 10;
    _valid = true;
    _loan = 0;
}

bool VIPAccount::loan(const double &num) {
    if (_valid == false) return false;
    if (_loan + num >= 1000) return false;
    if (num < 0) return false;
    _loan += num;
    _balance += num;
    return true;
}

bool VIPAccount::repay(const double &num) {
    if (num < 0 || _balance - num  < 0.01) return false;
    if (num > _loan) {
        reset();
    } else {
        _balance = _balance - num;
        _loan -= num;
    }
    return true;
}

string VIPAccount::profile() const {
    double limit = 1000;
    char a[300];
    memset(a, 0, sizeof(a));
    snprintf(a, sizeof(a),
    "ID:%d\nBALANCE:%.6lf\nVALID:Y\nTYPE:VIP\nLOAN:%.6lf,LIMIT:%.6lf\n",
    _id, _balance, _loan, limit);
    string temp(a);
    return temp;
}

