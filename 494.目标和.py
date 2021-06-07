# 转化成01背包问题

class Solution:
    def findTargetSumWays(self, nums: List[int], target: int) -> int:
        diff = sum(nums) - target
        if diff < 0 or diff % 2 == 1:
            return 0
        neg = diff//2
        dp = [0]*(neg+1)
        dp[0] = 1
        for num in nums:
            for i in range(neg, num-1, -1):
                dp[i] += dp[i-num]
        return dp[neg]
