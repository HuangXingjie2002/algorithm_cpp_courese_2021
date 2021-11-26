#include <iostream>
#include <vector>
#include <cmath>
using namespace std;


class Solution {
public:
    int mod = pow(10, 9) + 7; 
    int dp[31][1001];   
    /**
     * @brief 
     * 
     * @param d 骰子的个数
     * @param f 骰子的点数从 [1, 2, 3, ... , f]
     * @param target 目标值 
     * @return int 
     */
    int numRollsToTarget(int d, int f, int target) {
        /**
         * @brief 
         *  DP 思路
         *  在完成第i个的基础上达到target的最大数量。
         *  return dp[d][target]
         *  
         *  dp[i][j] = dp[i-1][j-k] k \in [1, 2, 3, 4, 5, ... , min(f, j - i + 1)]
         */
        
        if (f * d == target) 
            return 1;
        if (f * d < target) 
            return 0;

        for (int i = 1; i <= f; i ++) {
            dp[1][i] = 1;
        }

        for (int i = 2; i <= d; i ++) {
            // 枚举每一个骰子, 投掷
            // dp[i][j] = dp[i-1][j-k]
            // 所以说第 i 个骰子的分数k决定了dp更新时加上的种类数
            // k范围是k <= f
            for (int j = i; j <= target; j ++) {
                // 此时至少是i分
                for (int k = 1; k <= f; k ++) {
                    if (j <= k)
                        continue;
                    dp[i][j] = (dp[i][j] + dp[i-1][j-k]) % mod;
                }
            }
        }

        return dp[d][target] % mod;
    }
};

int main() {
    Solution sol;

    std::cout << sol.numRollsToTarget(20, 20, 100) << std::endl;
}