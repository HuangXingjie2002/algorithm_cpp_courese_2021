#include <iostream>
#include <vector>
#include <cmath>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findNthDigit(int n) {
        // 暴力把前n个字符串拼接起来返回第n-1个字符
        // 10 + 90
        unsigned long count = 0;
        long number = 0;
        for (int i = 1; i <= n + 1; i ++) {
            if (count >= n) {
                number = i-1;
                break;
            }

            count += log10(i) + 1;
        }

        unsigned long diff = count - n;
        string ans = to_string(number);
        return long(ans[ans.size() - 1 - diff] - '0');
    }
};
/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(m, n);
 * vector<int> param_1 = obj->flip();
 * obj->reset();
 */

int main() {
   Solution sol;
   vector<int> res;
   res.push_back(1);
   res.push_back(2);
   res.push_back(3);
   res.push_back(5);
//    std::cout << sol.kthSmallestPrimeFraction(res, 3) << std::endl;
    int ans = sol.findNthDigit(50);
    // for (int i = 0; i < ans.size(); i ++) {
    //     std::cout << ans[i] << std::endl;
    // }
    std::cout << ans << std::endl;
    // vector<int> a = {1, 2, 3, 4};
}