/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并 K 个升序链表
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
#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
  struct cmp {
    bool operator()(ListNode *l1, ListNode *l2) { return l1->val > l2->val; }
  };

  ListNode *mergeKLists(vector<ListNode *> &lists) {
    auto dummy = new ListNode(-1);
    auto p = dummy;

    priority_queue<ListNode *, vector<ListNode *>, cmp> pq;

    for (int i = 0; i < lists.size(); i++) {
      if (lists[i] != nullptr) {
        pq.push(lists[i]);
      }
    }

    while (!pq.empty()) {
      auto node = pq.top();
      pq.pop();
      p->next = node;
      if (node->next != nullptr) {
        pq.push(node->next);
      }
      p = p->next;
    }

    return dummy->next;
  }
};
// @lc code=end
