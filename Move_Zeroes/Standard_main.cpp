#include "other.hpp"
 
void moveZeroes(vector<int> & nums) {
    int size = nums.size();
    int pos = 0;
    for (int i = 0; i < size; i++) {
        if (nums[i] != 0) {
            int temp = nums[i];
            nums.erase(nums.begin() + i);
            nums.insert(nums.begin() + pos, temp);
            pos += 1;
        }
    }
}



//  learning note:
//  vector的清除可以用数字来表示位置，只要和begin()或者end()等迭代器联系起来就好。
