/*
 * @lc app=leetcode.cn id=155 lang=cpp
 *
 * [155] 最小栈
 */

// @lc code=start

// 两个栈：入栈的时候，同时把当前情况下的最小值也入栈
// 出栈同时出栈即可
#include <algorithm>
#include <climits>
#include <stack>

class MinStack {
  std::stack<int> s;
  std::stack<int> min;

public:
  MinStack() { min.push(INT_MAX); }

  void push(int x) {
    s.push(x);
    min.push(std::min(x, min.top()));
  }

  void pop() {
    s.pop();
    min.pop();
  }

  int top() { return s.top(); }

  int getMin() { return min.top(); }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end
