/*
 * @lc app=leetcode.cn id=226 lang=cpp
 *
 * [226] 翻转二叉树
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

// 左 --> 根 --> 右
class Solution {
public:
  TreeNode *invertTree(TreeNode *root) {
    if (root == nullptr) {
      return root;
    }

    auto left = invertTree(root->left);
    auto right = invertTree(root->right);

    root->left = right;
    root->right = left;

    return root;
  }
};
// @lc code=end
