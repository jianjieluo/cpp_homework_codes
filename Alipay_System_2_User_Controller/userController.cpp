#include "user.hpp"
#include <string>
#include <cstring>
#include <sstream>
#include "userController.hpp"
#include "global.hpp"
using namespace Alipay;

std::string doubleTranStr(double d) {
    std::stringstream ss;
    ss << d;
    return ss.str();
}

int userController::getUserIndex(const char* username) const {
    for (int i = 0; i < usercount; i++) {
        if (!strcmp(users[i] -> getUsername(), username)) {
            return i;
        }
    }
    return -1;
}

userController::userController(double interest_rate) {
    usercount = 0;
    setInterest(interest_rate);
}

userController::~userController() {
    for (int i = 0; i < usercount; i++) {
        delete users[i];
    }
}

bool userController::createUser(const char* username, const char* password) {
    if (strlen(username) > 20 || strlen(password) > 20 || strlen(username) < 6
    || strlen(password) < 8) {  // pay attention
        return false;
    } else {
        users[usercount++] = new user(username, password);
        return true;
    }
}

bool userController::deposite(const char* username, double amount) {
    int index = getUserIndex(username);
    if (index == -1) return false;
    return (users[index] -> deposite(amount));
}

bool userController::withdraw(const char* username, double amount) {
    int index = getUserIndex(username);
    if (index == -1) return false;
    return (users[index] -> withdraw(amount));
}

std::string userController::getUserInfoByName(const char* username) const {
    int index = getUserIndex(username);
    if (index == -1) {
        std::string temp = "No such user!";
        return temp;
    } else {
        std::string temp(users[index] -> getUsername());
        std::string a = "username:";
        a += temp;
        a += "\n";
        a += "password:*********\n";
        a += "balance:";
        a += doubleTranStr(users[index] -> getBalance());
        return a;
    }
}

int userController::getUserCount() const {
    return usercount;
}

bool userController::removeUserByUsername(const char* username) {
    int index = getUserIndex(username);
    if (index == -1) return false;
    delete users[index];
    for (int i = index; i < usercount - 1; i++) {
        users[i] = users[i + 1];
    }
    usercount--;
    return true;
}

bool userController::setInterest(double interest) {
    if (interest > 0) {
        interest_rate = interest;
        return true;
    } else {
        return false;
    }
}

void userController::payInterest(void) {
    for (int i = 0; i < usercount; i++) {
        double interest = users[i] -> getBalance() * interest_rate;
        users[i] -> deposite(interest);
    }
}

