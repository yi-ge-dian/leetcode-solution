/*
 * @lc app=leetcode.cn id=96 lang=cpp
 *
 * [96] 不同的二叉搜索树
 */

// @lc code=start
#include <vector>
class Solution {
public:
    int numTrees(int n) {
        std::vector<int> dp(n+1,0);
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2 ; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                dp[i] += dp[j-1] * dp[i-j];
            }
        }
        return dp[n];
    }
};
// @lc code=end

