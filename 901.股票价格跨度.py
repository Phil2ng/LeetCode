#
# @lc app=leetcode.cn id=901 lang=python3
#
# [901] 股票价格跨度
#

# @lc code=start
class StockSpanner:

    def __init__(self):
        self.stk = []
        self.idx = 0


    def next(self, price: int) -> int:
        self.idx += 1
        while self.stk and self.stk[-1][0] <= price:
            self.stk.pop()
        ret = self.idx - (self.stk[-1][1] if self.stk else 0)
        self.stk.append((price, self.idx))
        return ret
# Your StockSpanner object will be instantiated and called as such:
# obj = StockSpanner()
# param_1 = obj.next(price)
# @lc code=end

