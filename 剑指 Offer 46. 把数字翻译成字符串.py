# DP动态规划
class Solution:
    def translateNum(self, num: int) -> int:
        nums = list(map(int, list(str(num))))
        n = len(nums)
        dp = [1]*(n+1)
        for i in range(1, n):
            dp[i+1] = dp[i]
            if nums[i-1] == 1 or nums[i-1] == 2 and 0 <= nums[i] <= 5:
                dp[i+1] += dp[i-1]
        return dp[n]
