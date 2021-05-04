/*
 * @lc app=leetcode.cn id=1143 lang=cpp
 *
 * dp[i][j] 表示到第一个字符串位置i 为止、到第二个字符串位置j 为止、最长的公共子序列长度
 * dp[i][j] = dp[i-1][j-1] + 1,     当text1[i]==text2[j]
 *          = max{ dp[i-1][j], dp[i][j-1]},  其他
 * [1143] 最长公共子序列
 */

// @lc code=start
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2)
    {
        int m = text1.size(), n = text2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (int i = 1; i < m + 1; ++i)
        {
            for (int j = 1; j < n + 1; ++j)
            {
                if (text1[i - 1] == text2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return dp[m][n];
    }
    
};
// @lc code=end

