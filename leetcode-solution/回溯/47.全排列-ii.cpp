/*
 * @lc app=leetcode.cn id=47 lang=cpp
 *
 * [47] 全排列 II
 */

// @lc code=start
#include <algorithm>
#include <vector>
using namespace std;
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
      if (i > 0 && nums[i] == nums[i - 1] && used[i - 1] == false) {
        continue;
      }
      used[i] = true;
      path.push_back(nums[i]);
      backtracking(nums, used);
      used[i] = false;
      path.pop_back();
    }
  }
  vector<vector<int>> permuteUnique(vector<int> &nums) {
    vector<int> used(nums.size(), false);
    sort(nums.begin(), nums.end());
    backtracking(nums, used);
    return ans;
  }
};
// @lc code=end
