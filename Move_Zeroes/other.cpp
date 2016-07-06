#include "other.hpp"

vector<int>::iterator it;
void moveZeroes(vector<int> & nums) {
    int counter = 0;
    vector<int> temp;
    for (it = nums.begin(); it != nums.end(); ++it) {
        if (*it == 0) ++counter;
        else temp.push_back(*it);
    }
    while (counter--) {
        temp.push_back(0);
    }
    nums = temp;
}
