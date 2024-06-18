/*
 * @lc app=leetcode.cn id=343 lang=cpp
 *
 * [343] 整数拆分
 */

// @lc code=start
#include <algorithm>
#include <vector>
class Solution {
public:
  int integerBreak(int n) {
    std::vector<int> dp(n + 1, 0);
    dp[0] = 0;
    dp[1] = 0;
    dp[2] = 1;
    for (int i = 3; i <= n; i++) {
      for (int j = 1; j < i; j++) {
        dp[i] = std::max(dp[i], std::max((i - j) * j, dp[i - j] * j));
      }
    }
    return dp[n];
  }
};
// @lc code=end
