/*
 * @lc app=leetcode.cn id=458 lang=cpp
 *
 * [458] 可怜的小猪
 */

// @lc code=start
class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        return ceil((log2(buckets)) / log2((minutesToTest / minutesToDie) + 1));
    }
};
// @lc code=end

