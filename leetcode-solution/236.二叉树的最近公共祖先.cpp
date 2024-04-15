/*
 * @lc app=leetcode.cn id=236 lang=cpp
 *
 * [236] 二叉树的最近公共祖先
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
  TreeNode *traversal(TreeNode *root, TreeNode *p, TreeNode *q) {
    if (root == nullptr) {
      return root;
    }
    if (p == root || q == root) {
      return root;
    }

    auto left = traversal(root->left, p, q);
    auto right = traversal(root->right, p, q);
    if (left != nullptr && right != nullptr) {
      return root;
    }
    if (left != nullptr && right == nullptr) {
      return left;
    }
    if (right != nullptr && left == nullptr) {
      return right;
    }
    return nullptr;
  }

public:
  TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
    auto ans = traversal(root, p, q);
    return ans;
  }
};
// @lc code=end
