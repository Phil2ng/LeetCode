#
# @lc app=leetcode.cn id=879 lang=python3
#
# 背包问题
#
# [879] 盈利计划
#

# @lc code=start
class Solution:
    def profitableSchemes(self, n: int, minProfit: int, group: List[int], profit: List[int]) -> int:
        m = len(group)
        dp = [[0]*(minProfit+1) for _ in range(n+1)]
        for j in range(n+1):
            dp[j][0] = 1
        # dp[0][0] = 1
        for i in range(m):
            for j in range(n, group[i]-1, -1):
                for k in range(minProfit, -1, -1):
                    dp[j][k] = dp[j][k]+dp[j-group[i]][max(0, k-profit[i])]
        ans = dp[n][minProfit] % (10**9+7)
        # ans = sum(list(zip(*dp))[minProfit])%(10**9+7)
        return ans
# @lc code=end
