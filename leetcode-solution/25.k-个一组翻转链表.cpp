/*
 * @lc app=leetcode.cn id=25 lang=cpp
 *
 * [25] K 个一组翻转链表
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

// 思想来自于：https://www.bilibili.com/video/BV1kg4y137UU
class Solution {
public:
  ListNode *reverse(ListNode *head) {
    if (head == nullptr || head->next == nullptr) {
      return head;
    }

    ListNode *pre = nullptr;
    auto cur = head;
    while (cur != nullptr) {
      auto tmp = cur->next;
      cur->next = pre;
      pre = cur;
      cur = tmp;
    }
    return pre;
  }

  ListNode *reverseKGroup(ListNode *head, int k) {
    auto dummy = new ListNode(-1, head);
    auto pre = dummy;
    auto end = dummy;

    // 不停的走下去
    while (end != nullptr) {
      // 分组
      for (int i = 0; i < k && end != nullptr; i++) {
        end = end->next;
      }

      // 不够 k 个
      if (end == nullptr) {
        break;
      }

      auto next = end->next;
      end->next = nullptr;

      auto start = pre->next;
      pre->next = nullptr;

      // 进行反转
      pre->next = reverse(start);

      // 重新连接
      start->next = next;
      end = start;
      pre = start;
    }

    return dummy->next;
  }
};
// @lc code=end
