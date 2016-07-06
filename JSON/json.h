#ifndef JSON_H
#define JSON_H

#include <iostream>
#include <string>
#include <map>

using std::ostream;
using std::string;
using std::map;

class json {
 private:
    // store the relationship between key and value
    map<string, string> _data;
 public:
    // parse the raw string to map<string, string>
    explicit json(string);

    // return mutable value according to key
    string& operator[](string key) {
        return _data[key];
    }

    // return the number of key/value
    int count() const {
        return _data.size();
    }

    // output
    friend ostream& operator<<(ostream& os, const json& obj) {
        map<string, string>::iterator it;
        map<string, string> data = obj._data;
        int num = 0;
        os << "{\n";
        for (it = data.begin(); it != data.end(); it++) {
            num++;
            os << "    \"" << it->first << "\": \"" << it->second << "\"";
            if (num != obj.count()) {
                os << ",";
            }
            os << "\n";
        }
        os << "}";
        return os;
    }
};

#endif  // JSON_H

