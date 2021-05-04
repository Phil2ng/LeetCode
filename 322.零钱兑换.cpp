/*
 * @lc app=leetcode.cn id=322 lang=cpp
 *
 * 完全背包+恰好装满背包
 * dp[n][amount] = min{ dp[n][amount], dp[n][amount-coins[n]] + 1 }
 * 
 * [322] 零钱兑换
 */

// @lc code=start
class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        vector<int> dp(amount + 1, INT_MAX - 1);
        dp[0] = 0;
        for (int &coin : coins)
        {
            for (int i = coin; i <= amount; ++i)
            {
                dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }
        return dp[amount] == INT_MAX - 1 ? -1 : dp[amount];
    }
};
// @lc code=end
