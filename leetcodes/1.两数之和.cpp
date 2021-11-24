/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start

#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        /**
         * @brief 
         *  双重循环取值
         */
        
        bool flag = false;
        vector<int> vec;
        map<int, int> mapping;

        for (int i = 0; i < nums.size(); i ++) {
            if (mapping.find(target - nums[i]) != mapping.end()) {
                vec.push_back(mapping[target - nums[i]]);
                vec.push_back(i);
                flag = true;
            } else {
                mapping[nums[i]] = i;
            }
            if (flag) {
                break;
            }
        }
        return vec;
    }
};
// @lc code=end

