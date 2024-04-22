/*
 * @lc app=leetcode.cn id=114 lang=cpp
 *
 * [114] 二叉树展开为链表
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
 // 思路：去寻找左分支节点中的最右边的那个节点与 root->right 进行连接
class Solution {
public:
  void flatten(TreeNode *root) {
    if (root == nullptr) {
      return;
    }
    auto cur = root;
    while (cur != nullptr) {
      if (root->left != nullptr) {
        // 寻找左子树的最右孩子
        auto next = root->left;
        auto pre = next;
        while (pre->right != nullptr) {
          pre = pre->next;
        }

        pre->next = root->right;
        root->right = next;
        root->left = nullptr;
      }
      cur = cur->right;
    }
  }
};
// @lc code=end
