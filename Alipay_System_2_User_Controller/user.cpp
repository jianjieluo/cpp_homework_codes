#include <iostream>
#include <cstring>
#include <cstdio>
#include "user.hpp"
#include "global.hpp"
using namespace Alipay;

user::user(const char* username, const char* password) {
    balance = 0;
    setUsername(username);
    setPassword(password);
}

user::~user() {
    memset(this -> username, '0', 21);
    memset(this -> password, '0', 21);
    balance = 0;
}

const char* user::getUsername() const {
    return username;
}

const char* user::getPassword() const {
    return password;
}

const void user::setUsername(const char* username) {
    if (strlen(username) > 20) return;
    snprintf(this -> username, sizeof(this -> username), username);
}

const void user::setPassword(const char* password) {
    if (strlen(password) > 20) return;
    snprintf(this -> password, sizeof(this -> password), password);
}

double user::getBalance() {
    return balance;
}

bool user::withdraw(double amount) {
    if (amount < 0) return false;
    if (balance < amount) {
        return false;
    } else {
        balance -= amount;
        return true;
    }
}

bool user::deposite(double amount) {
    if (amount < 0) {
        return false;
    } else {
        balance += amount;
        return true;
    }
}

