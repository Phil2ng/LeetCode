# DP

class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        ans, tmp = 0, 0
        for i in range(1, len(prices)):
            tmp += prices[i]-prices[i-1]
            if tmp < 0:
                tmp = 0
            ans = max(ans, tmp)
        return ans
