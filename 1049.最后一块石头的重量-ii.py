#
# @lc app=leetcode.cn id=1049 lang=python3
#
# 转换成01背包问题
#
# [1049] 最后一块石头的重量 II
#

# @lc code=start
class Solution:
    def lastStoneWeightII(self, stones: List[int]) -> int:
        n = sum(stones)//2
        dp = [False]*(n+1)
        dp[0] = True
        for x in stones:
            for i in range(n, x-1, -1):
                dp[i] = dp[i] or dp[i-x]

        idx = n - dp[::-1].index(True)
        return sum(stones)-2*idx
# @lc code=end
