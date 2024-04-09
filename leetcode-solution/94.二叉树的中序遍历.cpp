/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] 二叉树的中序遍历
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

// 左-> 根 -> 右
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> inorderTraversal(TreeNode *root) {
    vector<int> ans;
    if (root == nullptr) {
      return ans;
    }

    auto left = inorderTraversal(root->left);
    ans.insert(ans.end(), left.begin(), left.end());

    ans.push_back(root->val);

    auto right = inorderTraversal(root->right);
    ans.insert(ans.end(), right.begin(), right.end());

    return ans;
  }
};
// @lc code=end
