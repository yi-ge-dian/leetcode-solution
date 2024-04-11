/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 */

// @lc code=start
#include <vector>
using namespace ::std;
class Solution {
public:
  vector<int> path;
  vector<vector<int>> ans;
  // 确定终止条件
  // 确定参数
  // 单层处理逻辑
  void backtracking(int n, int k, int startIndex) {
    if (path.size() == k) {
      ans.push_back(path);
      return;
    }

    // for (int i = startIndex; i <= n; i++) {
    // 优化的地方, n = 4，k = 4的话，那么第一层for循环的时候，从元素2开始的遍历都没有意义了。 在第二层for循环，从元素3开始的遍历都没有意义了。
    for (int i = startIndex; i <= n - (k - path.size()) + 1; i++) {
      path.push_back(i);
      backtracking(n, k, i + 1);
      path.pop_back();
    }
  }
  vector<vector<int>> combine(int n, int k) {
    backtracking(n, k, 1);
    return ans;
  }
};
// @lc code=end
