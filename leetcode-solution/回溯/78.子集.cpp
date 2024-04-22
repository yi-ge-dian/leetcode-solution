/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 */

// @lc code=start
#include <vector>
using namespace ::std;
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
      path.push_back(nums[i]);
      backtracking(nums, i + 1);
      path.pop_back();
    }
  }
  vector<vector<int>> subsets(vector<int> &nums) {
    backtracking(nums, 0);
    return ans;
  }
};
// @lc code=end
