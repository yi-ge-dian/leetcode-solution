/*
 * @lc app=leetcode.cn id=240 lang=cpp
 *
 * [240] 搜索二维矩阵 II
 */

// @lc code=start
#include <vector>
using namespace ::std;
class Solution {
public:
  bool searchMatrix(vector<vector<int>> &matrix, int target) {
    int row = matrix.size();
    int col = matrix[0].size();

    int i = 0;
    int j = col - 1;

    while (i < row && i >= 0 && j >= 0 && j < col) {
      if (matrix[i][j] == target) {
        return true;
      } else if (matrix[i][j] <= target) {
        i++;
      } else {
        j--;
      }
    }

    return false;
  }
};
// @lc code=end
