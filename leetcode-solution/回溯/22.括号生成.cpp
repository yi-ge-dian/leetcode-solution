/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 */

// @lc code=start
#include <string>
#include <vector>
using namespace std;

class Solution {
  vector<string> ans;
  string path;

public:
  void backtracking(int n, int left, int right) {
    if (path.size() == n * 2) {
      ans.push_back(path);
      return;
    }

    if (left < n) {
      path.push_back('(');
      backtracking(n, left + 1, right);
      path.pop_back();
    }

    if (left > right) {
      path.push_back(')');
      backtracking(n, left, right + 1);
      path.pop_back();
    }
  }
  vector<string> generateParenthesis(int n) {
    backtracking(n, 0, 0);
    return ans;
  }
};
// @lc code=end
