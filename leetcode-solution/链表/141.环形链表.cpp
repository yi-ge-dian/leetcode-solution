/*
 * @lc app=leetcode.cn id=141 lang=cpp
 *
 * [141] 环形链表
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
class Solution {
public:
  bool hasCycle(ListNode *head) {
    if (head == nullptr || head->next == nullptr) {
      return false;
    }

    auto fast = head->next;
    auto slow = head;
    while (fast != nullptr && fast->next != nullptr) {
      if (fast == slow) {
        return true;
      }
      fast = fast->next->next;
      slow = slow->next;
    }

    return false;
  }
};
// @lc code=end
