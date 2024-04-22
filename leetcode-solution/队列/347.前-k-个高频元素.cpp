/*
 * @lc app=leetcode.cn id=347 lang=cpp
 *
 * [347] 前 K 个高频元素
 */

// @lc code=start
#include <queue>
#include <unordered_map>
#include <utility>
#include <vector>
using namespace ::std;
class Solution {
public:
  vector<int> topKFrequent(vector<int> &nums, int k) {
    vector<int> ans;
    unordered_map<int, int> hm;
    for (int x : nums) {
      hm[x]++;
    }

    // 频次是 first，数字为 second
    priority_queue<pair<int, int> > pq;
    for (auto it : hm) {
      pq.push(make_pair(it.second, it.first));
    }

    while (k--) {
        ans.push_back(pq.top().first);
        pq.pop();
    }
    return ans;
  }
};
// @lc code=end
