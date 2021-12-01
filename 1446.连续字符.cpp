/*
 * @lc app=leetcode.cn id=1446 lang=cpp
 *
 * [1446] 连续字符
 */

// @lc code=start
class Solution
{
public:
    int maxPower(string s)
    {
        int ans = 1, tmp = 1;
        for (int i = 1; i < s.size(); i++)
        {
            if (s[i] == s[i - 1])
            {
                tmp++;
                ans = max(ans, tmp);
            }
            else
                tmp = 1;
        }
        return ans;
    }
};
// @lc code=end

