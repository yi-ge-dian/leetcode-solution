/*
 * @lc app=leetcode.cn id=234 lang=cpp
 *
 * [234] 回文链表
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

// 遍历一遍 + 双指针
#include <vector>
using namespace std;
class Solution {
public:
  bool isPalindrome(ListNode *head) {
    vector<int> nums;
    auto p = head;
    while (p != nullptr) {
      nums.push_back(p->val);
      p = p->next;
    }

    int r = nums.size() - 1;
    int l = 0;
    while (l < r) {
      if (nums[l] != nums[r]) {
        return false;
      } else {
        r--;
        l++;
      }
    }

    return true;
  }
};
// @lc code=end
