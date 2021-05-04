/*
 * @lc app=leetcode.cn id=221 lang=cpp
 *
 * dp[r][c] = k 为以(r,c)为右下顶点的正方形边长为k
 * dp[r][c] = min{ dp[r-1][c-1], dp[r-1][c], dp[r][c-1] } + 1;
 * 
 * [221] 最大正方形
 */

// @lc code=start
class Solution {
public:
    int maximalSquare(vector<vector<char>> &matrix)
    {
        int m = matrix.size(), n = matrix[0].size(), ans = 0;
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (matrix[i][j] == '1')
                {
                    dp[i + 1][j + 1] = min(dp[i][j], min(dp[i][j + 1], dp[i + 1][j])) + 1;
                }
                ans = max(ans, dp[i + 1][j + 1]);
            }
        }
        return ans * ans;
    }
};
// @lc code=end

