/*
 * @lc app=leetcode.cn id=216 lang=cpp
 *
 * [216] 组合总和 III
 */

// @lc code=start

// 确定参数
// 确定终止条件
// 确定单层遍历
#include <vector>
using namespace std;
class Solution {
  vector<vector<int>> ans;
  vector<int> path;

public:
  void backtracking(int k, int targetSum, int sum, int startIndex) {
    // 确定终止条件
    if (sum > targetSum) {
      return;
    }
    if (path.size() == k) {
      if (targetSum == sum) {
        ans.push_back(path);
      }
      return;
    }
    // 确定单层条件
    for (int i = startIndex; i <= 9 - (k - path.size()) + 1; i++) {
      path.push_back(i);
      sum += i;

      backtracking(k, targetSum, sum, i + 1);
      sum -= i;
      path.pop_back();
    }
  }
  vector<vector<int>> combinationSum3(int k, int n) {
    backtracking(k, n, 0, 1);
    return ans;
  }
};
// @lc code=end
