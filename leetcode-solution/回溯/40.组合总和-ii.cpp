/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和 II
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
  // 确定返回参数
  vector<vector<int>> ans;
  vector<int> path;
  int sum;

public:
  void backtracking(vector<int> &candidates, int target, int sum,
                    int startIndex) {
    // 确定终止条件
    if (target == sum) {
      ans.push_back(path);
    } else if (sum > target) {
      return;
    }

    // 单层处理
    for (int i = startIndex; i < candidates.size(); i++) {
      if (i > startIndex && candidates[i] == candidates[i - 1]) {
        continue;
      }
      path.push_back(candidates[i]);
      sum += candidates[i];
      backtracking(candidates, target, sum, i + 1);
      sum -= candidates[i];
      path.pop_back();
    }
  }
  vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
    sort(candidates.begin(), candidates.end());
    backtracking(candidates, target, 0, 0);
    return ans;
  }
};
// @lc code=end
