/*
 * @lc app=leetcode.cn id=807 lang=cpp
 *
 * 贪心
 * 
 * [807] 保持城市天际线
 */

// @lc code=start
class Solution
{
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>> &grid)
    {
        int m = grid.size(), n = grid[0].size(), ans = 0;
        vector<int> min_cow(m), min_row(n);
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                min_cow[i] = max(min_cow[i], grid[i][j]);
                min_row[j] = max(min_row[j], grid[i][j]);
            }
        }
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                ans += min(min_cow[i], min_row[j]) - grid[i][j];
            }
        }
        return ans;
    }
};
// @lc code=end

