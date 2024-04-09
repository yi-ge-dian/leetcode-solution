/*
 * @lc app=leetcode.cn id=148 lang=cpp
 *
 * [148] 排序链表
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
  ListNode *sortList(ListNode *head) {
    if (head == nullptr || head->next == nullptr) {
      return head;
    }
    auto slow = head;
    auto fast = head;
    while (fast->next != nullptr && fast->next->next != nullptr) {
      fast = fast->next->next;
      slow = slow->next;
    }

    auto tmp = slow->next;
    slow->next = nullptr;
    auto l = sortList(head);
    auto r = sortList(tmp);

    auto dummy = new ListNode(-1);
    auto p = dummy;
    while (l != nullptr && r != nullptr) {
      if (l->val <= r->val) {
        p->next = l;
        l = l->next;
      } else {
        p->next = r;
        r = r->next;
      }
      p = p->next;
    }
    if (l != nullptr) {
      p->next = l;
    }
    if (r != nullptr) {
      p->next = r;
    }

    return dummy->next;
  }
};
// @lc code=end
