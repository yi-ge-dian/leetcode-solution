/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
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
  TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
    if (preorder.size() != inorder.size() || preorder.size() == 0) {
      return nullptr;
    }
    // 先序：根-左-右
    // 中序：左-根-右
    int index = 0;
    for (int i = 0; i < inorder.size(); i++) {
      if (inorder[i] == preorder[0]) {
        index = i;
        break;
      }
    }
    // 获得 index
    if (index == -1) {
      return nullptr;
    }
    // 当前根节点
    auto root = new TreeNode(preorder[0]);

    // 左子树前序遍历
    vector<int> lchildpre(preorder.begin() + 1, preorder.begin() + 1 + index);

    // 左子树中序遍历
    vector<int> lchildin(inorder.begin(), inorder.begin() + index);

    // 左子树
    root->left = buildTree(lchildpre, lchildin);

    // 右子树前序遍历
    vector<int> rchildpre(preorder.begin() + 1 + index, preorder.end());

    // 右子树中序遍历
    vector<int> rchildin(inorder.begin() + 1 + index, inorder.end());

    // 右子树
    root->right = buildTree(rchildpre, rchildin);

    return root;
  }
};
// @lc code=end
