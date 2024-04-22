/*
 * @lc app=leetcode.cn id=104 lang=cpp
 *
 * [104] 二叉树的最大深度
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

// 左， 右 ， 根
class Solution {
public:
  int maxDepth(TreeNode *root) {
    int ans = 0;
    if (root == nullptr) {
      return ans;
    }
    auto left_depth = maxDepth(root->left);

    auto right_depth = maxDepth(root->right);

    ans = left_depth > right_depth ? left_depth + 1 : right_depth + 1;
    return ans;
  }
};
// @lc code=end
