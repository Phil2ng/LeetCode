/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        unordered_map<char, int> mp;
        int ans = 0, pre = 0;
        for (int i = 0; i < s.length(); ++i)
        {
            pre = max(pre, mp[s[i]]);
            ans = max(ans, i - pre + 1);
            mp[s[i]] = i + 1;
        }
        return ans;
    }
};
// @lc code=end
