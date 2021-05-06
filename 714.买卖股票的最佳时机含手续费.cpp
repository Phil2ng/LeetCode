/*
 * @lc app=leetcode.cn id=714 lang=cpp
 *
 * 状态机转移
 * 或者贪心只要涨了就卖，只要降了就标记买
 * 
 * [714] 买卖股票的最佳时机含手续费
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int> &prices, int fee)
    {
        int n = prices.size();
        vector<int> buy(n), s1(n), sell(n), s2(n);
        s1[0] = buy[0] = -prices[0], sell[0] = s2[0] = 0;
        for (int i = 1; i < n; ++i)
        {
            buy[i] = max(sell[i - 1], s2[i - 1]) - prices[i];
            s1[i] = max(s1[i - 1], buy[i - 1]);
            sell[i] = max(buy[i - 1], s1[i - 1]) + prices[i] - fee;
            s2[i] = max(s2[i - 1], sell[i - 1]);
        }
        return max(sell[n - 1], s2[n - 1]);
    }
};
// @lc code=end

