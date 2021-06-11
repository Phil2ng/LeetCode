#
# @lc app=leetcode.cn id=279 lang=python3
#
# dp[n] = 1 + min(dp[n-1],dp[n-4],...,dp[n-k*k])
#
# [279] 完全平方数
#

# @lc code=start
class Solution:
    def numSquares(self, n: int) -> int:
        dp = [0] + [10000]*(n+1)
        for i in range(1, n+1):
            for k in range(1, int(math.sqrt(n))+1):
                dp[i] = min(dp[i], dp[i-k*k])
            dp[i] += 1
        return dp[n]
# @lc code=end
