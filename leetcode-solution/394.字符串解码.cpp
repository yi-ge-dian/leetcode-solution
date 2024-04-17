/*
 * @lc app=leetcode.cn id=394 lang=cpp
 *
 * [394] 字符串解码
 */

// @lc code=start
#include <cctype>
#include <iterator>
#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
  string decodeString(string s) {
    stack<int> num_st;
    string ans;
    int num = 0;
    for (int i = 0; i < s.size(); i++) {
      if (isdigit(s[i])) {
        num = num * 10 + s[i] - '0';
      } else {
        if (s[i] == '[') {
          num_st.push(num);
          ans += s[i];
          num = 0;
        } else if (s[i] >= 'a' && s[i] <= 'z') {
          ans += s[i];
        } else {
          // 一直出栈，直到出现 ']'
          vector<char> temp;
          while (ans.back() != '[') {
            auto back = ans.back();
            ans.pop_back();
            temp.push_back(back);
          }
          ans.pop_back();
          auto num = num_st.top();
          num_st.pop();

          while (num--) {
            for (auto it = temp.end() - 1; it >= temp.begin(); it--) {
              ans += *it;
            }
          }
        }
      }
    }

    return ans;
  }
};
// @lc code=end
