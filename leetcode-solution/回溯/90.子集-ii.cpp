/*
 * @lc app=leetcode.cn id=90 lang=cpp
 *
 * [90] 子集 II
 */

// @lc code=start
#include <algorithm>
#include <vector>
using namespace std;
class Solution {
  vector<vector<int>> ans;
  vector<int> path;

public:
  void backtracking(vector<int> &nums, int startIndex) {
    ans.push_back(path);
    if (startIndex == nums.size()) {
      return;
    }

    for (int i = startIndex; i < nums.size(); i++) {
      if (i > startIndex && nums[i] == nums[i - 1]) {
        continue;
      }
      path.push_back(nums[i]);
      backtracking(nums, i + 1);
      path.pop_back();
    }
  }
  vector<vector<int>> subsetsWithDup(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    backtracking(nums, 0);
    return ans;
  }
};
// @lc code=end
