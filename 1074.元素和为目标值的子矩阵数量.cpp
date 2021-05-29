/*
 * @lc app=leetcode.cn id=1074 lang=cpp
 *
 * [1074] 元素和为目标值的子矩阵数量
 */

// @lc code=start
class Solution
{
public:
    int numSubmatrixSumTarget(vector<vector<int>> &matrix, int target)
    {
        int m = matrix.size(), n = matrix[0].size(), ans = 0, t = 0;
        int dp[m + 1][n + 1];
        memset(dp, 0, sizeof dp);
        for (int i = 1; i <= m; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + matrix[i - 1][j - 1];
                for (int x = 1; x <= i; ++x)
                {
                    for (int y = 1; y <= j; ++y)
                    {
                        if (target == (dp[i][j] - dp[i][y - 1] - dp[x - 1][j] + dp[x - 1][y - 1]))
                            ++ans;
                    }
                }
            }
        }
        return ans;
    }
    // int numSubmatrixSumTarget(vector<vector<int>> &matrix, int target)
    // {
    //     int m = matrix.size(), n = matrix[0].size(), ans = 0;
    //     // int dp[m + 1][n + 1];
    //     // memset(dp, 0, sizeof dp);
    //     vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    //     for (int i = 1; i <= m; ++i)
    //     {
    //         for (int j = 1; j <= n; ++j)
    //         {
    //             dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + matrix[i - 1][j - 1];
    //         }
    //     }
    //     for (int top = 1; top <= m; ++top)
    //     {
    //         for (int bot = top; bot <= m; ++bot)
    //         {
    //             unordered_map<int, int> hash;
    //             hash[0] = 1;
    //             for (int col = 1; col <= n; ++col)
    //             {
    //                 int cur = dp[bot][col] - dp[top - 1][col];
    //                 if (hash.find(cur - target) != hash.end())
    //                     ans += hash[cur - target];
    //                 ++hash[cur];
    //             }
    //         }
    //     }
    //     return ans;
    // }
};
// @lc code=end
