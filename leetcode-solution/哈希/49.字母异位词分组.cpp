/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] 字母异位词分组
 */

// @lc code=start
#include<vector>
#include<unordered_map>
#include<string>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> hm;
        for(int i = 0 ; i < strs.size(); i++){
            auto str = strs[i];
            sort(str.begin(),str.end());
            hm[str].push_back(strs[i]);
        }

        for(const auto & it : hm){
            ans.push_back(it.second);
        }

        return ans;
    }
};
// @lc code=end

