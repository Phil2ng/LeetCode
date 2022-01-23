#
# @lc app=leetcode.cn id=2034 lang=python3
#
# [2034] 股票价格波动
#

# @lc code=start
from sortedcontainers import SortedList
class StockPrice:
    def __init__(self):
        self.price = SortedList()
        self.dic = defaultdict(int)
        self.maxTimestamp = 0

    def update(self, timestamp: int, price: int) -> None:
        self.price.discard(self.dic[timestamp])
        self.maxTimestamp = max(self.maxTimestamp, timestamp)
        self.price.add(price)
        self.dic[timestamp] = price

    def current(self) -> int:
        return self.dic[self.maxTimestamp]

    def maximum(self) -> int:
        return self.price[-1]

    def minimum(self) -> int:
        return self.price[0]


# Your StockPrice object will be instantiated and called as such:
# obj = StockPrice()
# obj.update(timestamp,price)
# param_2 = obj.current()
# param_3 = obj.maximum()
# param_4 = obj.minimum()
# @lc code=end

