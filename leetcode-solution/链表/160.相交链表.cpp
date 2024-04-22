/*
 * @lc app=leetcode.cn id=160 lang=cpp
 *
 * [160] 相交链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// 两个链表如果是相交的，走的长度是相等的
class Solution {
public:
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    auto l1 = headA;
    auto l2 = headB;

    while (l1 != l2) {
      l1 = l1 == nullptr ? headB : l1->next;
      l2 = l2 == nullptr?  headA : l2->next;
    }

    return l1;
  }
};
// @lc code=end
