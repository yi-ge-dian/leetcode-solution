/*
 * @lc app=leetcode.cn id=124 lang=cpp
 *
 * [124] 二叉树中的最大路径和
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
  int ans = INT_MIN;

public:
  int traversal(TreeNode *root) {
    if (root == nullptr) {
      return 0;
    }
    auto left = traversal(root->left);
    if (left < 0) {
      left = 0;
    }
    auto right = traversal(root->right);
    if (right < 0) {
      right = 0;
    }

    ans = max(ans, root->val + left + right);
    return root->val + max(left, right);
  }
  int maxPathSum(TreeNode *root) {
    traversal(root);
    return ans;
  }
};
// @lc code=end
