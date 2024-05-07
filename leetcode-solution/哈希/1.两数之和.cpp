/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        unordered_map<int, int> hm; 

        for(int i = 0 ; i < nums.size(); i++){
            auto toFind = target - nums[i];
            if(hm.count(toFind)){
                ans.push_back(hm[toFind]);
                ans.push_back(i);
                return ans;
            }else{
                hm[nums[i]]=i;
            }
        }

        return {-1,-1};
    }
};
// @lc code=end
