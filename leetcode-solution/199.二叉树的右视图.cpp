/*
 * @lc app=leetcode.cn id=199 lang=cpp
 *
 * [199] 二叉树的右视图
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

#include <ios>
#include <queue>
#include <vector>
using namespace std;
class Solution {
public:
  vector<int> rightSideView(TreeNode *root) {
    vector<int> ans;
    queue<TreeNode *> q;
    if (root == nullptr) {
      return ans;
    }

    q.push(root);

    while (!q.empty()) {
      int size = q.size();
      for (int i = 0; i < size; i++) {
        auto node = q.front();
        q.pop();
        if (node->left != nullptr) {
          q.push(node->left);
        }
        if (node->right != nullptr) {
          q.push(node->right);
        }
        if (i == size - 1) {
          ans.push_back(node->val);
        }
      }
    }

    return ans;
  }
};
// @lc code=end
