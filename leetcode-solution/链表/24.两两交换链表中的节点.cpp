/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
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

// 指针需要指到反转节点的前一个节点才可以
class Solution {
public:
  ListNode *swapPairs(ListNode *head) {
    auto dummy = new ListNode(-1, head);
    auto cur = dummy;
    while (cur->next != nullptr && cur->next->next != nullptr) {
      auto tmp = cur->next;
      cur->next = cur->next->next;

      auto tmp2 = cur->next->next;
      cur->next->next = tmp;
      tmp->next = tmp2;

      cur = cur->next->next;
    }
    return dummy->next;
  }
};
// @lc code=end
