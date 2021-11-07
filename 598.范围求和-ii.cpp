/*
 * @lc app=leetcode.cn id=598 lang=cpp
 *
 * 数学
 * 
 * [598] 范围求和 II
 */

// @lc code=start
class Solution
{
public:
    int maxCount(int m, int n, vector<vector<int>> &ops)
    {
        for (auto &&a : ops)
        {
            m = min(m, a[0]);
            n = min(n, a[1]);
        }
        return m * n;
    }
};
// @lc code=end

