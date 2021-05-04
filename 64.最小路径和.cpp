/*
 * @lc app=leetcode.cn id=64 lang=cpp
 *
 * dp[r][c] = min(dp[r-1][c], dp[r][c-1]) + grid[r][c]
 * 
 * [64] 最小路径和
 */

// @lc code=start
class Solution
{
public:
    int minPathSum(vector<vector<int>> &grid)
    {
        int m = grid.size(), n = grid[0].size();
        vector<int> dp(n + 1, INT_MAX); //边界填充极大值
        dp[1] = 0;
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                dp[j + 1] = min(dp[j], dp[j + 1]) + grid[i][j];
            }
        }
        return dp[n];
    }
};
// @lc code=end
