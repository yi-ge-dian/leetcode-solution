/*
 * @lc app=leetcode.cn id=131 lang=cpp
 *
 * [131] 分割回文串
 */

// @lc code=start
#include <vector>
using namespace ::std;
class Solution {
  vector<vector<string>> ans;
  vector<string> path;

public:
  bool isPalindrome(string s, int start, int end) {
    int i = start;
    int j = end;
    while (i < j) {
      if (s[i] != s[j]) {
        return false;
      }
      i++;
      j--;
    }
    return true;
  }

  void backtracking(string s, int startIndex) {
    // 进行收获
    if (startIndex == s.size()) {
      ans.push_back(path);
      return;
    }

    for (int i = startIndex; i < s.size(); i++) {
      if (isPalindrome(s, startIndex, i)) {
        path.push_back(s.substr(startIndex, i - startIndex + 1));
      } else {
        continue;
      }
      backtracking(s, i + 1);
      path.pop_back();
    }
  }

  vector<vector<string>> partition(string s) {
    backtracking(s, 0);
    return ans;
  }
};
// @lc code=end
