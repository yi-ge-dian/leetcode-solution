/*
 * @lc app=leetcode.cn id=543 lang=cpp
 *
 * [543] 二叉树的直径
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

//      x
//   x
// x    x
//   x     x
// x 
class Solution {
  int max_depth_;

public:
  int maxDepth(TreeNode *root) {
    if (root == nullptr) {
      return 0;
    }

    auto left = maxDepth(root->left);
    auto right = maxDepth(root->right);
    max_depth_ = max(max_depth_, left + right); // 这一步是有必要的，因为有可能根节点的情况不是最大的

    return max(left, right) + 1;
  }

  int diameterOfBinaryTree(TreeNode *root) {
    maxDepth(root);
    return max_depth_;
  }
};
// @lc code=end
