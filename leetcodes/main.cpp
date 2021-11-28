#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
using namespace std;


class Solution {
public:
    int find(vector<int> &vec, int target) {
        if (target <= vec[0]) return 0;

        int lo(0), hi(vec.size()), mid((lo + hi) >> 1);

        while (mid != lo) {
            if (vec[mid] == target) {
                return mid - 1;
            } else if (vec[mid] < target) {
                lo = mid;
            } else {
                hi = mid;
            }
            mid = (lo + hi) >> 1;
        }

        return hi;
    }

    int sum(vector<int> &vec,int begin, int length) {
        int summation = 0;
        for (int i = 0; i < length; i ++) {
            summation += vec[i+begin];
        }
        return summation;
    }

    int findBestValue(vector<int>& arr, int target) {
        // n logn 二分查找 + 区间遍历
        // 预处理寻找小于等于target的值加入到 vec中求和，并且得到一个长度
        /*
        arr数组， target为期望达到的目标值
        输出value变为何值的时候会出现target
        1. 排序后得到一个从小到大的矩阵，统计每个区间的个数
        */

        unordered_map<int, int> map;

        sort(arr.begin(), arr.end());

        for (int i = arr.size() - 1; i >= 0; i --) {
            if (!map.count(arr[i])) {
                map[arr[i]] = arr.size() - i;
            } else {
                map[arr[i]] ++;
            }
        }

        // 如上得到一个排序好的向量与大于某个值的数。

        int res = target / (arr.size() * 2);
        // 从res 开始逐渐递增，直到找到一个最小的
        // 起初的时候肯定是偏小的，直到delta 变正的时候
        int minA(arr[0]), maxA(arr[arr.size() - 1] > target ? arr[arr.size() - 1] : target);


        vector<int> tamp(maxA - minA + 1);
        for (int i = 0; i < tamp.size(); i ++) {
            int index = find(arr, i + minA);
            int summation = sum(arr, 0, index) + map[arr[index]] * (i + minA);
            tamp[i] = abs(summation - target);
        }

        return res - 1;
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
   res.push_back(4);
   res.push_back(9);
   res.push_back(3);

   std::cout << sol.findBestValue(res, 10) << std::endl;
}