/*
 * @lc app=leetcode.cn id=494 lang=cpp
 *
 * dp[i][j]表示遍历到i和为j的方法数
 * dp[i][j + nums[i]] += dp[i-1][j]
 * dp[i][j - nums[i]] += dp[i-1][j]
 * 
 * [494] 目标和
 */

// @lc code=start
class Solution
{
public:
    int findTargetSumWays(vector<int> &nums, int target)
    {
        int n = nums.size();
        vector<vector<int>> dp(n + 2, vector<int>(4002, 0));
        dp[0][0 + 2000] = 1;
        for (int i = 1; i <= n; ++i)
        {
            for (int j = -1000; j <= 1000; j++)
            {
                if (dp[i - 1][j + 2000] > 0)
                {
                    dp[i][j + nums[i - 1] + 2000] += dp[i - 1][j + 2000];
                    dp[i][j - nums[i - 1] + 2000] += dp[i - 1][j + 2000];
                }
            }
        }
        return target <= 1000 ? dp[n][target + 2000] : 0;
    }
};
// @lc code=end
