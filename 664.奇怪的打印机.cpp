/*
 * @lc app=leetcode.cn id=664 lang=cpp
 *
 * 分治/动态规划
 * dp[i][j] 表示打印完成区间 [i,j] 的最少操作数
 * 
 * [664] 奇怪的打印机
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    int strangePrinter(string s)
    {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n));
        for (int i = n - 1; i >= 0; --i)
        {
            dp[i][i] = 1;
            for (int j = i + 1; j < n; ++j)
            {
                if (s[i] == s[j])
                {
                    dp[i][j] = dp[i][j - 1];
                }
                else
                {
                    int t = INT_MAX;
                    for (int k = i; k < j; ++k)
                    {
                        t = min(t, dp[i][k] + dp[k + 1][j]);
                    }
                    dp[i][j] = t;
                }
            }
        }
        return dp[0][n - 1];
    }
};
// @lc code=end
