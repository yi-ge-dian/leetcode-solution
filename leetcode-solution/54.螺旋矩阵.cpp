/*
 * @lc app=leetcode.cn id=54 lang=cpp
 *
 * [54] 螺旋矩阵
 */

// @lc code=start
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> spiralOrder(vector<vector<int>> &matrix) {
    int row = matrix.size();
    int col = matrix[0].size();

    // 定义四个边界
    int left = 0;
    int up = 0;
    int right = col - 1;
    int bottom = row - 1;

    vector<int> ans;

    while (true) {
      // 从左到右
      if (left <= right) {
        for (int i = left; i <= right; i++) {
          ans.push_back(matrix[up][i]);
        }
        up++;
      } else {
        break;
      }

      // 从上到下
      if (up <= bottom) {
        for (int i = up; i <= bottom; i++) {
          ans.push_back(matrix[i][right]);
        }
        right--;
      } else {
        break;
      }

      // 从右到左
      if (right >= left) {
        for (int i = right; i >= left; i--) {
          ans.push_back(matrix[bottom][i]);
        }
        bottom--;
      } else {
        break;
      }

      // 从下到上
      if (bottom >= up) {
        for (int i = bottom; i >= up; i--) {
          ans.push_back(matrix[i][left]);
        }
        left++;
      } else {
        break;
      }
    }

    return ans;
  }
};
// @lc code=end
