#
# @lc app=leetcode.cn id=1518 lang=python3
#
# [1518] 换酒问题
#

# @lc code=start
class Solution:
    def numWaterBottles(self, numBottles: int, numExchange: int) -> int:
        ans = numBottles
        while numBottles >= numExchange:
            ans += numBottles//numExchange
            numBottles = (numBottles % numExchange) + (numBottles//numExchange)
        return ans

# @lc code=end

