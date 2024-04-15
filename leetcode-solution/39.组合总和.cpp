/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 */

// @lc code=start

// 确定参数

#include <vector>
using namespace std;

class Solution {
  vector<vector<int>> ans;
  vector<int> path;
  int sum;

public:
  void backtracking(vector<int> &candidates, int target, int sum,
                    int startIndex) {
    // 确定终止条件
    if (sum == target) {
      ans.push_back(path);
    } else if (sum > target) {
      return;
    }

    // 确定单层遍历
    for (int i = startIndex; i < candidates.size(); i++) {
      path.push_back(candidates[i]);
      sum += candidates[i];
      backtracking(candidates, target, sum, i);
      sum -= candidates[i];
      path.pop_back();
    }
  }
  vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
    backtracking(candidates, target, 0, 0);
    return ans;
  }
};
// @lc code=end
