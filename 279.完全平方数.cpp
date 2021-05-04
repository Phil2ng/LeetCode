/*
 * @lc app=leetcode.cn id=279 lang=cpp
 *
 * dp[n]=k, 和为n的完全平方数的 最少数量k
 * dp[n] = 1 + min{ dp[n-1], dp[n-4], dp[n-9], ...}
 * [279] 完全平方数
 */

// @lc code=start
class Solution
{
public:
    int numSquares(int n)
    {
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j * j <= i; ++j)
            {
                dp[i] = min(dp[i], dp[i - j * j] + 1);
            }
        }
        return dp[n];
    }
};
// @lc code=end
