/*
 * @lc app=leetcode.cn id=295 lang=cpp
 *
 * [295] 数据流的中位数
 */

// @lc code=start
#include <functional>
#include <queue>
#include <vector>
using namespace std;
class MedianFinder {
  // 大根堆 - 小根堆 = 1
  priority_queue<int> max_pq; // 大根堆，存放较小的
  priority_queue<int, vector<int>, greater<int>> min_pq; // 小根堆，存放较大的

public:
  MedianFinder() {}

  void addNum(int num) {
    // 无脑大顶堆
    max_pq.push(num);

    // 超过了规定
    if (max_pq.size() - min_pq.size() > 1) {
      int num = max_pq.top();
      max_pq.pop();
      min_pq.push(num);
    }
    // 大根堆 > 小根堆，进行维护
    while (max_pq.top() > min_pq.size()) {
      int max = max_pq.top();
      int min = min_pq.top();
      max_pq.pop();
      min_pq.pop();
      min_pq.push(max);
      max_pq.push(min);
    }
  }

  double findMedian() {
    double res = 0;
    // 奇数
    if ((max_pq.size() + min_pq.size()) % 2) {
      res = max_pq.top();
    } else {
      // 偶数
      res = double(max_pq.top() + min_pq.top()) / 2;
    }
    return res;
  }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
// @lc code=end
