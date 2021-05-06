/*
 * @lc app=leetcode.cn id=343 lang=cpp
 *
 * DP：dp[n] = max{ dp[k]*dp[n-k], (1<=k<n/2) }
 * 数学法：尽可能的拆分成2,3
 * 
 * [343] 整数拆分
 */

// @lc code=start
class Solution
{
public:
    int integerBreak(int n)
    {
        vector<int> dp = {0, 1, 2, 3};
        for (int i = 4; i <= n; ++i)
        {
            int tmp = 0;
            for (int k = 1; k <= i / 2; ++k)
            {
                tmp = max(tmp, dp[k] * dp[i - k]);
            }
            dp.push_back(tmp);
        }
        dp[1] = 0, dp[2] = 1, dp[3] = 2;
        return dp[n];
    }
};
// @lc code=end
