# DP

class Solution:
    def dicesProbability(self, n: int) -> List[float]:
        dp = [0] * (n*6+1)
        for i in range(1, 7):
            dp[i] = 1
        for i in range(2, n+1):
            for j in range(i*6, i-1, -1):
                dp[j] = 0
                for k in range(1, 7):
                    if j-k >= i-1:
                        dp[j] += dp[j-k]
        all = 6**n
        ans = []
        for i in range(n, n*6+1):
            ans.append(dp[i]/all)
        return ans
