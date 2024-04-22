/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
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
class Solution {
public:
  bool isSymmetric(TreeNode *root) {
    if (root == nullptr) {
      return true;
    }

    return bfs(root->left, root->right);
  }

  bool bfs(TreeNode *left, TreeNode *right) {
    // 左右孩子都为空
    if (left == nullptr && right == nullptr) {
      return true;
    }
    // 左右孩子有一个为空
    if (left == nullptr || right == nullptr) {
      return false;
    }
    // 左右孩子不等
    if (left->val != right->val) {
      return false;
    }

    return bfs(left->left, right->right) && bfs(left->right, right->left);
  }
};
// @lc code=end
