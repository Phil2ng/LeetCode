/*
 * 区间问题--贪心算法
 *
 * [122] 买卖股票的最佳时机 II
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int> &prices) {
		int ans = 0, n = prices.size();
		for (int i = 1; i < n; i++) {
			ans += max(0, prices[i] - prices[i - 1]);
		}
		return ans;
	}
};
// @lc code=end

