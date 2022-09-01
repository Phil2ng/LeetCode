#
# @lc app=leetcode.cn id=1475 lang=python3
#
# [1475] 商品折扣后的最终价格
#

# @lc code=start
class Solution:
    def finalPrices(self, prices: List[int]) -> List[int]:
        n = len(prices)
        ans = [0] * n
        stk = [0]
        for i in range(n-1, -1, -1):
            while stk[-1]!=0 and stk[-1] > prices[i]:
                stk.pop()
            ans[i] = prices[i] - stk[-1]
            stk.append(prices[i])
        return ans
# @lc code=end

