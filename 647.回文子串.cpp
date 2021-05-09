/*
 * @lc app=leetcode.cn id=647 lang=cpp
 *
 * [647] 回文子串
 */

// @lc code=start
class Solution
{
public:
    int countSubstrings(string s)
    {
        int count = 0;
        for (int i; i < s.length(); ++i)
        {
            count += extendSubstrings(s, i, i);
            count += extendSubstrings(s, i, i + 1);
        }
        return count;
    }
    int extendSubstrings(string s, int l, int r)
    {
        int count = 0;
        while (l >= 0 && r < s.length() && s[l] == s[r])
        {
            ++count;
            l--, r++;
        }
        return count;
    }
};
// @lc code=end
