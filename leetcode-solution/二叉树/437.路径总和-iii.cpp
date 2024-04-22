/*
 * @lc app=leetcode.cn id=437 lang=cpp
 *
 * [437] 路径总和 III
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
  // 确定参数
  int ans = 0;
  long long sum = 0;

public:
  void backtracking(TreeNode *root, int targetSum) {
    if (sum == targetSum) {
      ans++;
    }
    if (root->left) {
      sum += root->left->val;
      backtracking(root->left, targetSum);
      sum -= root->left->val;
    }
    if (root->right) {
      sum += root->right->val;
      backtracking(root->right, targetSum);
      sum -= root->right->val;
    }
  }

  void traverse(TreeNode *root, int targetSum) {
    // 终止条件
    if (root == nullptr) {
      return;
    }
    sum = root->val;
    backtracking(root, targetSum);
    traverse(root->left, targetSum);
    traverse(root->right, targetSum);
  }
  int pathSum(TreeNode *root, int targetSum) {
    traverse(root, targetSum);
    return ans;
  }
};
// @lc code=end
