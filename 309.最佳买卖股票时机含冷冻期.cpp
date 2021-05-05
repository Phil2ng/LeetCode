/*
 * @lc app=leetcode.cn id=309 lang=cpp
 *
 * [309] 最佳买卖股票时机含冷冻期
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        if (n == 0)
            return 0;
        vector<int> buy(n), s1(n), sell(n), s2(n);
        buy[0] = s1[0] = -prices[0];
        sell[0] = s2[0] = 0;
        for (int i = 1; i < n; ++i)
        {
            buy[i] = s2[i - 1] - prices[i];
            s1[i] = max(s1[i - 1], buy[i - 1]);
            sell[i] = max(buy[i - 1], s1[i - 1]) + prices[i];
            s2[i] = max(s2[i - 1], sell[i - 1]);
        }
        return max(sell[n - 1], s2[n - 1]);
    }
};
// @lc code=end

