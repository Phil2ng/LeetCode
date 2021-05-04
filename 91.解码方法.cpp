/*
 * @lc app=leetcode.cn id=91 lang=cpp
 *
 * dp[n] = 0/dp[n-1] + 0/dp[n-2]
 * 
 * [91] 解码方法
 */

// @lc code=start
class Solution {
public:
    int numDecodings(string s)
    {
        int n = s.length(), prev = s[0] - '0';
        if (!prev)
            return 0;
        vector<int> dp(n + 1, 1);
        for (int i = 2; i <= n; ++i)
        {
            int cur = s[i - 1] - '0';
            if (cur == 0)
            {
                if (prev == 0 || prev > 2)
                    return 0;
                else
                    dp[i] = dp[i - 2];
            }
            else
            {
                dp[i] = dp[i - 1];
                if (prev == 1 || prev == 2 && cur <= 6)
                    dp[i] += dp[i - 2];
            }
            prev = cur;
        }
        return dp[n];
    }

};
// @lc code=end

