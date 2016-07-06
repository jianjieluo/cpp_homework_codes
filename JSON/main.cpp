#include <iostream>
#include <string>
#include "json.h"

using std::cin;
using std::string;
using std::cout;
using std::endl;

int main(void) {
    {
        // {"name":"lilei","country":"china","age":"20"}
        json test("{\"name\":\"lilei\",\"country\":\"china\",\"age\":\"20\"}");
        cout << test << endl;
        test["name"] = "mike";
        test["country"] = "USA";
        cout << test << endl;
    }
    {
        // {"book_name":"c++ primer 5th","price":"$19.99"}
        json test("{\"book_name\":\"c++ primer 5th\",\"price\":\"$19.99\"}");
        cout << test << endl;
        test["page"] = "345";
        test["ISBN"] = "978-962";
        cout << test << endl;
    }
    {
        int AvoidRepeatedData;
        cin >> AvoidRepeatedData;
        string rawString;
        cin >> rawString;
        json test(rawString);
        cout << test << endl;
    }
    return 0;
}

