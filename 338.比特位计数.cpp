/*
 * @lc app=leetcode.cn id=338 lang=cpp
 *
 * [338] 比特位计数
 */

// @lc code=start
class Solution
{
public:
    vector<int> countBits(int num)
    {
        vector<int> dp(num + 1, 0);
        for (int i = 1; i <= num; ++i)
        {
            // dp[i] = dp[i >> 1] + (i & 1);
            // dp[i] = i & i ? dp[i - 1] + 1 : dp[i >> 1];
            dp[i] = dp[i & (i - 1)] + 1;
        }
        return dp;
    }
};
// @lc code=end
