/*
 * @lc app=leetcode.cn id=63 lang=cpp
 *
 * [63] 不同路径 II
 */

// @lc code=start
#include <vector>
using namespace ::std;
class Solution {
public:
  int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();
    std::vector<std::vector<int>> dp(m, std::vector<int>(n, 0));
    for (int j = 0; j < n && obstacleGrid[0][j] != 0; j++) {
      dp[0][j] = 1;
    }

    for (int i = 0; i < m && obstacleGrid[i][0] != 0; i++) {
      dp[i][0] = 1;
    }

    for (int i = 1; i < m; i++) {
      for (int j = 1; j < n; j++) {
        if (obstacleGrid[i][j] != 0) {
          dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        } else {
          dp[i][j] = 0;
        }
      }
    }

    return dp[m-1][n-1];
  }
};
// @lc code=end
