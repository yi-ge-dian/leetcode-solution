/*
 * @lc app=leetcode.cn id=230 lang=cpp
 *
 * [230] 二叉搜索树中第K小的元素
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
  int ans;
  void dfs(TreeNode *root, int &num, int k) {
    if (root == nullptr) {
      return;
    }

    dfs(root->left, num, k);
    num++;
    if (num == k) {
      ans = root->val;
    }
    dfs(root->right, num, k);
  }

  int kthSmallest(TreeNode *root, int k) {
    int num = 0;
    dfs(root, num, k);
    return ans;
  }
};
// @lc code=end
