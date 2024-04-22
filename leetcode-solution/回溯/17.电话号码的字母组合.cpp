/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */

// @lc code=start
#include <string>
#include <vector>
using namespace std;
class Solution {
  const string letterMap[10] = {" ",   " ",   "abc",  "def", "ghi",
                                "jkl", "mno", "pqrs", "tuv", "wxyz"};
  // 定义返回值
  vector<string> ans;
  string path;

public:
  void backtracking(string digits, int index) {
    // 确定终止条件
    if (index == digits.size()) {
      ans.push_back(path);
      return;
    }

    // 单层处理逻辑
    int digit = digits[index] - '0';
    string letters = letterMap[digit];
    for (int i = 0; i < letters.size(); i++) {
      path.push_back(letters[i]);
      backtracking(digits, index + 1);
      path.pop_back();
    }
  }
  vector<string> letterCombinations(string digits) {
    if (digits.size() == 0) {
      return ans;
    }
    backtracking(digits, 0);
    return ans;
  }
};
// @lc code=end
