#include <string>
#include <cstring>
#include "user.hpp"
using namespace alipay;

inline bool  User::verifyUsernameFormat(const std::string &username) {
  bool judge = true;
  int length = username.length();
  if (length > 20 || length < 6)
    judge = false;
  for (int i = 0; i < length; i++) {
    if (!((username[i] > 47 && username[i] < 58) || (username[i] > 64 &&
    username[i] < 91) || (username[i] > 96 && username[i] < 123)))
    judge = false;
  }
  return judge;
}

inline bool User::verifyPasswordFormat(const std::string &password) {
  bool judge = true;
  int length = password.length();
  if (length > 20 || length < 8)
    judge = false;
  for (int i = 0; i < length; i++) {
    if (password[i] < 48) judge = false;
    else if (password[i] > 57 && password[i] < 65) judge = false;
    else if (password[i] > 90 && password[i] < 97) judge = false;
    else if (password[i] > 122) judge = false;
  }
  return judge;
}

inline bool User::verifyPhoneFormat(const std::string &phone) {
  bool judge = true;
  int length = phone.length();
  if (length != 13) judge = false;
  for (int i = 0; i < length; i++) {
    if (phone[i] < '0' || phone[i] > '9')
      judge = false;
  }
  return judge;
}

bool User::setUsername(const char *username) {
  bool judge = true;
  std::string str(username);
  if (verifyUsernameFormat(str)) this -> username = str;
  else judge = false;
  return judge;
}

bool User::setPassword(const char *new_password, const char* old_password) {
  bool judge = true;
  std::string new_(new_password);
  std::string old_(old_password);
  std::string str;
  if (password != old_) judge = false;
  if (verifyPasswordFormat(new_)) password = new_;
  else judge = false;
  return judge;
}

bool User::setPhone(const char *new_phone) {
  bool judge = true;
  std::string str(new_phone);
  int length = str.length();
  if (length != 13) judge = false;
  for (int i = 0; i < length; i++) {
    if (!(new_phone[i] > 47 && new_phone[i] < 58))
      judge = false;
  }
  if (judge) phone = str;
  return judge;
}

bool User::setGender(Gender::Gender gender) {
  this -> gender = gender;
  if (this -> gender != Gender::Unknown) return true;
  else return false;
}

long long int User::getMoneyAmount(const char* password) {
  if (this -> password != password) {
    return -1;
  } else {
    return balance;
  }
}

bool User::deposit(long long int amount) {
  if (amount < 0) {
    return false;
  } else {
    balance += amount;
    return true;
  }
}

bool User::withdraw(long long int amount, const char *password) {
  bool judge = true;
  if (amount < 0) judge = false;
  if (balance < amount) judge = false;
  else balance -= amount;
  return judge;
}

std::string User::getUsername(void) {
  return username;
}
std::string User::getPhone() {
  return phone;
}
alipay::Gender::Gender User::getGender() {
  return gender;
}
