/*
 * @lc app=leetcode.cn id=128 lang=cpp
 *
 * [128] 最长连续序列
 */

// @lc code=start
#include<unordered_map>
#include<vector>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int , int> hm;
        int ans = 0 ;
        for(const auto & x :nums){
            hm[x] = 1;
        }


        for(const auto &it : hm){
            if(it.second){
                auto x = it.first;
                int len = 1;
                // 向左寻找
                for(int i = 1; hm.count(x-i) && hm[x-i]; i++ ){
                    len++;
                    hm[x-i] = 0;
                }

                // 向右寻找
                for(int i = 1; hm.count(x+i) && hm[x+i]; i++ ){
                    len++;
                    hm[x+i] = 0;
                }

                ans = max(ans, len);
            }            
        }
        return ans;
    }
};
// @lc code=end

