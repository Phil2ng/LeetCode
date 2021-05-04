/*
 * @lc app=leetcode.cn id=542 lang=cpp
 *
 * 从左上到右下、从右下到左上 两次动态搜索即可完成四个方向的查找。
 * dp[r][c] = min{ dp[r][c], dp[r-1][c], dp[r][c-1], dp[r+1][c], dp[r][c+1]}
 * 
 * [542] 01 矩阵
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> updateMatrix(vector<vector<int>> &matrix)
    {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, INT_MAX - 1));
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (matrix[i][j] == 0)
                    dp[i][j] = 0;
                else
                {
                    if (j > 0)
                        dp[i][j] = min(dp[i][j], dp[i][j - 1] + 1);
                    if (i > 0)
                        dp[i][j] = min(dp[i][j], dp[i - 1][j] + 1);
                }
            }
        }
        for (int i = m - 1; i >= 0; --i)
        {
            for (int j = n - 1; j >= 0; --j)
            {
                if (matrix[i][j] == 0)
                    dp[i][j] = 0;
                else
                {
                    if (j < n - 1)
                        dp[i][j] = min(dp[i][j], dp[i][j + 1] + 1);
                    if (i < m - 1)
                        dp[i][j] = min(dp[i][j], dp[i + 1][j] + 1);
                }
            }
        }
        return dp;
    }
    
};
// @lc code=end
