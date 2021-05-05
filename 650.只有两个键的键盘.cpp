/*
 * @lc app=leetcode.cn id=650 lang=cpp
 *
 * dp[n] = min{ dp[n/k] + k,(其中k=2,3,...,n) };
 * 
 * [650] 只有两个键的键盘
 */

// @lc code=start
class Solution {
public:
    int minSteps(int n)
    {
        vector<int> dp(n + 1, n);
        dp[1] = 0;
        for (int i = 2; i <= n; ++i)
        {
            for (int k = 2; k <= i; ++k)
            {
                if (i % k == 0)
                    dp[i] = min(dp[i], dp[i / k] + k);
            }
        }
        return dp[n];
    }
};
// @lc code=end

