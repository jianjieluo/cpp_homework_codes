#include "VB.hpp"
#include <string>
#include <stdio.h>
#include <iostream>

int main() {
    char num[2000];
    gets(num);
    std::string temp(num);
    std::cout << isNumber(temp);
    return 0;
}

