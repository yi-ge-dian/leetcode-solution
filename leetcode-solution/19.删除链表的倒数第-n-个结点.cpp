/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第 N 个结点
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

// 双指针：先让快指针走 n 步
class Solution {
public:
  ListNode *removeNthFromEnd(ListNode *head, int n) {
    auto dummy = new ListNode(-1, head);
    auto fast = dummy;
    while (n--) {
      fast = fast->next;
    }
    auto slow = dummy;
    while (fast->next != nullptr) {
      fast = fast->next;
      slow = slow->next;
    }

    slow->next = slow->next->next;
    return dummy->next;
  }
};
// @lc code=end
