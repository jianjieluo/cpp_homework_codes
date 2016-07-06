#include <iostream>
#include <vector>
#include "other.hpp"

using std::vector;

void display(const vector<int> & nums) {
    int size = nums.size();
    std::cout << "[";
    for (int i = 0; i < size; i++) {
        std::cout << nums[i] << ", ";
    }
    std::cout << "]" << std::endl;
}

int main() {
    int n = 0;
    std::cin >> n;
    std::vector<int> nums;
    while (n--) {
        int temp = 0;
        std::cin >> temp;
        nums.push_back(temp);
    }

    moveZeroes(nums);
    display(nums);

    return 0;
}


