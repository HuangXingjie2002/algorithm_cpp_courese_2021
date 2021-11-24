/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int buffer = 0, sum = 0;
        ListNode * tamp;
        ListNode * t = new ListNode(0);
        tamp = t;
        int la, lb;
        while (l1 != nullptr || l2 != nullptr || buffer != 0) {
            la = l1 ? l1->val : 0;
            lb = l2 ? l2->val : 0;
            if (buffer != 0)
                sum = (la + lb + buffer) % 10;
            else
                sum = (la + lb) % 10;
            ListNode * buffer1 = new ListNode(sum);
            t->next = buffer1;
            t = t->next;

            buffer = (la + lb + buffer) / 10;
            if (l1 != nullptr) {
                l1 = l1->next;
            }
            if (l2 != nullptr) {
                l2 = l2->next;
            }
        }
        return tamp->next;
    }
};
// @lc code=end

