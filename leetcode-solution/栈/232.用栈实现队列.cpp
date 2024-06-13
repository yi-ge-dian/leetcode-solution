/*
 * @lc app=leetcode.cn id=232 lang=cpp
 *
 * [232] 用栈实现队列
 */

// @lc code=start

// 两个栈：s1 负责入队操作  s2 负责出队操作
// 入队直接入即可，出队时候需要判断s2是否为空
// 如果不为空，s2 直接出栈即可
// 如果为空，把s1的东西都弄到s2里面再出栈即可
#include <stack>
class MyQueue {
  std::stack<int> s1;
  std::stack<int> s2;

public:
  MyQueue() {}

  void push(int x) { s1.push(x); }

  int pop() {
    if (!s2.empty()) {
      int res = s2.top();
      s2.pop();
      return res;
    } else {
      while (!s1.empty()) {
        s2.push(s1.top());
        s1.pop();
      }
      int x = s2.top();
      s2.pop();
      return x;
    }
  }

  int peek() {
    if (s2.empty()) {
      while (!s1.empty()) {
        s2.push(s1.top());
        s1.pop();
      }
    }
    return s2.top();
  }

  bool empty() { return s1.empty() && s2.empty(); }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
// @lc code=end
