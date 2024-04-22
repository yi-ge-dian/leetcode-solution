/*
 * @lc app=leetcode.cn id=138 lang=cpp
 *
 * [138] 随机链表的复制
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
// 思路来源：https://www.bilibili.com/video/BV1mf4y1E7qv
#include <unordered_map>
class Solution {
public:
  Node *copyRandomList(Node *head) {
    if (head == nullptr) {
      return nullptr;
    }

    auto cur = head;
    unordered_map<Node *, Node *> hm;
    while (cur != nullptr) {
      auto new_node = new Node(cur->val);
      hm[cur] = new_node;
      cur = cur->next;
    }

    cur = head;
    while (cur != nullptr) {
      auto new_node = hm[cur];
      auto origin_next_node = cur->next;
      auto origin_random_node = cur->random;

      auto new_next_node = hm[origin_next_node];
      auto new_random_node = hm[origin_random_node];

      new_node->next = new_next_node;
      new_node->random = new_random_node;

      cur = cur->next;
    }

    return hm[head];
  }
};
// @lc code=end
