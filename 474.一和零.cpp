/*
 * @lc app=leetcode.cn id=474 lang=cpp
 *
 * 二维费用01背包
 * dp[k][i][j] = 1 + max{ dp[k-1][i][j], dp[k-1][i-cnt0][j-cnt1] }
 * 
 * [474] 一和零
 */

// @lc code=start
class Solution {
public:
    int findMaxForm(vector<string> &strs, int m, int n)
    {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (const string &str : strs)
        {
            auto [cnt0, cnt1] = count01(str);
            for (int i = m; i >= cnt0; --i)
            {
                for (int j = n; j >= cnt1; --j)
                {
                    dp[i][j] = max(dp[i][j], dp[i - cnt0][j - cnt1] + 1);
                }
            }
        }
        return dp[m][n];
    }
    pair<int, int> count01(string str)
    {
        int cnt0 = 0, cnt1 = 0;
        for (const char c : str)
        {
            if (c == '0')
                ++cnt0;
            else
                ++cnt1;
        }
        return {cnt0, cnt1};
    }
};
// @lc code=end

