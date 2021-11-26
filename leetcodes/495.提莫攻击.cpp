/*
 * @lc app=leetcode.cn id=495 lang=cpp
 *
 * [495] 提莫攻击
 */

// @lc code=start
class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        // 两种状态
        // 1. 在中毒事件内攻击， 重置
        // 2. 在中毒事件外攻击， 从0开始计数
        // 事件间隔超过2秒，则重新开始计时，
        // 事件间隔两秒之内，刷新
        // 使用循环变量表示下一次中毒持续到了什么时候

        int count = 0;

        for (int i = 1; i < timeSeries.size(); i ++) {
            count += timeSeries[i] - timeSeries[i-1] >= duration ? duration : timeSeries[i] - timeSeries[i-1];
        }

        return count + duration;
    }
};
// @lc code=end

