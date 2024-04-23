/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */

// @lc code=start
#include <vector>
using namespace ::std;

class Solution {
  vector<vector<int>> ans;
  vector<int> path;

public:
  void backtracking(vector<int> &nums, vector<int> used) {
    if (path.size() == nums.size()) {
      ans.push_back(path);
      return;
    }

    for (int i = 0; i < nums.size(); i++) {
      if (used[i]) {
        continue;
      }
      used[i] = true;
      path.push_back(nums[i]);
      backtracking(nums, used);
      used[i] = false;
      path.pop_back();
    }
  }
  vector<vector<int>> permute(vector<int> &nums) {
    vector<int> used(nums.size(), false);
    backtracking(nums, used);
    return ans;
  }
};
// @lc code=end
