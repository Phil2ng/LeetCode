/*
 * @lc app=leetcode.cn id=877 lang=cpp
 *
 * [877] 石子游戏
 */

// @lc code=start
class Solution
{
public:
    bool stoneGame(vector<int> &piles)
    {
        int n = piles.size();
        vector<vector<int>> dp = vector<vector<int>>(n, vector<int>(n, 0));
        for (int i = n - 1; i > -1; --i)
        {
            dp[i][i] = piles[i];
            for (int j = i + 1; j < n; j++)
            {
                dp[i][j] = max(piles[i] - dp[i + 1][j], piles[j] - dp[i][j - 1]);
            }
        }
        return dp[0][n - 1];
    }
};
// @lc code=end
