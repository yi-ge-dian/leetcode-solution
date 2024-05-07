/*
 * @lc app=leetcode.cn id=45 lang=cpp
 *
 * [45] 跳跃游戏 II
 */

// @lc code=start
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();

        if(n <= 1){
            return 0;
        }

        int end = 0;
        int step = 0;
        int maxPostion = 0;

        for (int i = 0 ; i < n; i++){
            maxPostion = max(maxPostion, i + nums[i]);
            if(i == end){
                end = maxPostion;
                step++;
                if(end >= n-1) break;
            }
        }

        return step;
    }
};
// @lc code=end

