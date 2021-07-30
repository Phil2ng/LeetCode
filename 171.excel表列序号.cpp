/*
 * @lc app=leetcode.cn id=171 lang=cpp
 *
 * [171] Excel表列序号
 */

// @lc code=start

class Solution
{
public:
    int titleToNumber(string columnTitle)
    {
        int ans = 0;
        for (auto &&c : columnTitle)
        {
            ans = ans * 26 + (c - 'A' + 1);
        }
        return ans;
    }
};
// @lc code=end

