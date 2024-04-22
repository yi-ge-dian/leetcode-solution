/*
 * @lc app=leetcode.cn id=48 lang=cpp
 *
 * [48] 旋转图像
 */

// @lc code=start
#include <array>
#include <vector>
using namespace std;

class Solution {
public:
  void rotate(vector<vector<int>> &matrix) {
    // [row,col] ===> [col,n-1-row]

    int n = matrix.size();
    // 水平反转 ===> [row,col]===> [n-1-row, col]
    for (int i = 0; i < n / 2; i++) {
      for (int j = 0; j < n; j++) {
        swap(matrix[i][j], matrix[n - 1 - i][j]);
      }
    }
    // 对角线交换
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < i; j++) {
        swap(matrix[i][j], matrix[j][i]);
      }
    }
  }
};
// @lc code=end
