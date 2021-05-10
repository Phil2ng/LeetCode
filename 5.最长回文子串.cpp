/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */

// @lc code=start
class Solution {
public:
    string longestPalindrome(string s)
    {
        int maxLen = 0;
        string ans;
        for (int i = 0; i < s.length(); ++i)
        {
            auto p = expandAroundCenter(s,i,i);
            if(p.second-p.first>maxLen){
                maxLen = p.second-p.first;
                ans = s.substr(p.first,maxLen);
            }
            p = expandAroundCenter(s,i,i+1);
            if(p.second-p.first>maxLen){
                maxLen = p.second-p.first;
                ans = s.substr(p.first,maxLen);
            }
        }
        return ans;
    }
    pair<int, int> expandAroundCenter(string s, int l, int r)
    {
        while (l >= 0 && r < s.length() && s[l] == s[r])
        {
            --l, ++r;
        }
        return {++l, r};
    }
};
// @lc code=end

