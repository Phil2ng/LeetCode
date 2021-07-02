#
# @lc app=leetcode.cn id=1833 lang=python3
#
# [1833] 雪糕的最大数量
#

# @lc code=start
class Solution:
    def maxIceCream(self, costs: List[int], coins: int) -> int:
        costs.sort()
        ans = 0
        for cost in costs:
            coins -= cost
            if coins < 0:
                break
            ans += 1
        return ans
# @lc code=end
