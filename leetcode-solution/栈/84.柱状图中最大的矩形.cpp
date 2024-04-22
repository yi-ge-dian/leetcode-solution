/*
 * @lc app=leetcode.cn id=84 lang=cpp
 *
 * [84] 柱状图中最大的矩形
 */

// @lc code=start
#include <algorithm>
#include <stack>
using namespace std;
class Solution {
public:
  int largestRectangleArea(vector<int> &heights) {
    int ans = 0;
    stack<int> st;
    heights.insert(heights.begin(), 0);
    heights.push_back(0);
    st.push(0);

    for (int i = 1; i < heights.size(); i++) {
      // 维护一个单调递减栈
      if (heights[i] >= heights[st.top()]) {
        st.push(i);
      } else {
        while (!st.empty() && heights[i] < heights[st.top()]) {
          int mid = st.top();
          st.pop();
          int left = st.top();
          int right = i;
          int area = (right - left - 1) * heights[i];
          ans = max(ans, area);
        }
        st.push(i);
      }
    }
    return ans;
  }
};
// @lc code=end
