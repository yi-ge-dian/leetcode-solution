/*
 * @lc app=leetcode.cn id=215 lang=cpp
 *
 * [215] 数组中的第K个最大元素
 */

// @lc code=start
#include <functional>
#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int ,vector<int>, greater<int> >  pq;        
        for (int i = 0; i < k ; i++) {
            pq.push(nums[i]);
        }

        for (int i = k; i < nums.size(); i++) {
            if (pq.top() < nums[i]) {
                pq.pop();
                pq.push(nums[i]);
            }
        }
        return pq.top();
    }
};
// @lc code=end

