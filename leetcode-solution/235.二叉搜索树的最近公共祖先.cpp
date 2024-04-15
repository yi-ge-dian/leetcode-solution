/*
 * @lc app=leetcode.cn id=235 lang=cpp
 *
 * [235] 二叉搜索树的最近公共祖先
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
    if (root->val > p->val && root->val > q->val) {
      auto left = traversal(root->left, p, q);
      if (left != nullptr) {
        return left;
      }
    }
    if (root->val < p->val && root->val < q->val) {
      auto right = traversal(root->right, p, q);
      if (right != nullptr) {
        return right;
      }
    }
    return root;
  }

public:
  TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
    auto ans = traversal(root, p, q);
    return ans;
  }
};
// @lc code=end
