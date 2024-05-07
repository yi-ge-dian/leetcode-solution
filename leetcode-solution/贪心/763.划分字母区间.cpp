/*
 * @lc app=leetcode.cn id=763 lang=cpp
 *
 * [763] 划分字母区间
 */

// @lc code=start
class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> ans;
        unordered_map<int, int> hm;

        for(int i = 0; i < s.size(); i++){
            hm[s[i]]=i;
        }

        int start = 0;
        int end = 0;

        for(int i = 0; i < s.size(); i++){
            end = max(end, hm[s[i]]);
            if(i == end){
                ans.push_back(end-start+1);
                start = end+1;
            }
        }
        return ans;
    }
};
// @lc code=end

