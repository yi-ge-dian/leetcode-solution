/*
 * @lc app=leetcode.cn id=739 lang=cpp
 *
 * [739] 每日温度
 */

// @lc code=start

#include <stack>
#include <vector>
using namespace std;
class Solution {
  stack<int> st;
  vector<int> ans;

public:
  vector<int> dailyTemperatures(vector<int> &temperatures) {
    st.push(0);
    for (int i = 1; i < temperatures.size(); i++) {
      if (temperatures[i] < temperatures[st.top()]) {
        st.push(i);
      } else if (temperatures[i] == temperatures[st.top()]) {
        st.push(i);
      } else {
        while (!st.empty() && temperatures[i] > temperatures[st.top()]) {
          int top = st.top();
          st.pop();
          ans[top] = i - top;
        }
        st.push(i);
      }
    }

    return ans;
  }
};
// @lc code=end
