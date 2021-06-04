# DP动态规划
# dp[n] = dp[n-1] + dp[n-2]

class Solution:
    def numWays(self, n: int) -> int:
        a, b = 1, 1
        for _ in range(n):
            a, b = b, a+b
        return a % 1000000007
