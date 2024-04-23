/*
 * @lc app=leetcode.cn id=491 lang=cpp
 *
 * [491] 非递减子序列
 */

// @lc code=start
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
  vector<vector<int>> ans;
  vector<int> path;

public:
  void backtracking(vector<int> &nums, int startIndex) {
    if (path.size() > 1) {
      ans.push_back(path);
    }

    if (startIndex == nums.size()) {
      return;
    }

    for (int i = startIndex; i < nums.size(); i++) {
      unordered_map<int, int> hm;

      if (!path.empty() && nums[i] < path.back() || hm.count(nums[i])) {
        continue;
      }
      hm[nums[i]] = 1;
      path.push_back(nums[i]);
      backtracking(nums, i + 1);
      path.pop_back();
    }
  }

  vector<vector<int>> findSubsequences(vector<int> &nums) {
    backtracking(nums, 0);
    return ans;
  }
};
// @lc code=end
