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
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    auto dummy = new ListNode();
    auto p = dummy;
    auto p1 = l1;
    auto p2 = l2;

    int t = 0;

    while (p1 != nullptr || p2 != nullptr || t) {
      int sum = t;

      if (p1 != nullptr) {
        sum += p1->val;
        p1 = p1->next;
      }
      if (p2 != nullptr) {
        sum += p2->val;
        p2 = p2->next;
      }

      int val = sum % 10;
      t = sum / 10;

      auto new_node = new ListNode(val);
      p->next = new_node;
      p = p->next;
    }
    return dummy->next;
  }
};
// @lc code=end
