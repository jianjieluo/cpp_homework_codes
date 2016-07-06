#include <iostream>
#include <string>
#include <set>

std::set<std::string>::iterator it;

void change_case(std::string & str) {
    int size = static_cast<int>(str.size());
    for (int i = 0; i < size; ++i) {
        if (str[i] >= 97) str[i] -= 32;
    }
}

int main(void) {
    int n, m;
    while (1) {
        std::cin >> n;
        if (n == 0) return 0;
        std::cin >> m;
        std::set<std::string> friends_set;
        std::set<std::string> senders_set;
        while (n--) {
            std::string temp;
            std::cin >> temp;
            change_case(temp);
            friends_set.insert(temp);
        }
        while (m--) {
            std::string temp;
            std::cin >> temp;
            change_case(temp);
            senders_set.insert(temp);
        }
        unsigned int counter = 0;
        for (it = friends_set.begin(); it != friends_set.end(); ++it) {
            if (senders_set.find(*it) != senders_set.end()) ++counter;
        }
        std::cout << friends_set.size() - counter << std::endl;
    }
    return 0;
}

