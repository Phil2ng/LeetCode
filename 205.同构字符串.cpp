/*
 * @lc app=leetcode.cn id=205 lang=cpp
 *
 * 相同位置的字符,与它上一次出现的位置一样
 * 
 * [205] 同构字符串
 */

// @lc code=start
class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {
        vector<int> sPreIndex(256, 0), tPreIndex(256, 0);
        for (int i = 0; i < s.length(); ++i)
        {
            if (sPreIndex[s[i]] != tPreIndex[t[i]])
                return false;
            sPreIndex[s[i]] = tPreIndex[t[i]] = i + 1;
        }
        return true;
    }
};
// @lc code=end
