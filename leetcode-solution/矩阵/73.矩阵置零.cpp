/*
 * @lc app=leetcode.cn id=73 lang=cpp
 *
 * [73] 矩阵置零
 */

// @lc code=start
#include <vector>

using namespace std;
class Solution {
public:
  void setZeroes(vector<vector<int>> &matrix) {
    auto row = matrix.size();
    auto col = matrix[0].size();

    vector<int> vi_row(row, 1);
    vector<int> vi_col(col, 1);

    for (int i = 0; i < row; i++) {
      for (int j = 0; j < col; j++) {
        if (matrix[i][j] == 0) {
          vi_row[i] = 0;
          vi_col[j] = 0;
        }
      }
    }

    for (int i = 0; i < row; i++) {
      for (int j = 0; j < col; j++) {
        if (vi_row[i] == 0 || vi_col[j] == 0) {
          matrix[i][j] = 0;
        }
      }
    }

  }
};
// @lc code=end
