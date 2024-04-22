/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
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
  using ll = long long;
  const ll INF = 1e18;
  bool isValidBST(TreeNode *root) { return dfs(root, -INF, INF); }

  bool dfs(TreeNode *root, ll lower, ll upper) {
    if (root == nullptr) {
      return true;
    }
    if (root->val <= lower || root->val >= upper) {
      return false;
    }
    return dfs(root->left, lower, root->val) &&
           dfs(root->right, root->val, upper)
  }
};
// @lc code=end
