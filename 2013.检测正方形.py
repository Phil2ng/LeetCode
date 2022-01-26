#
# @lc app=leetcode.cn id=2013 lang=python3
#
# [2013] 检测正方形
#

# @lc code=start
class DetectSquares:

    def __init__(self):
        self.cnt = defaultdict(int)


    def add(self, point: List[int]) -> None:
        self.cnt[(point[0], point[1])] += 1


    def count(self, point: List[int]) -> int:
        cnt = self.cnt
        x, y = point
        ret = 0
        for i in range(0, 1001):
            if i == x:
                continue
            j = y - x + i
            if 0 <= j <= 1000:
                ret += cnt[(i,j)] * cnt[(x,j)] * cnt[(i,y)]
            j = y + x - i
            if 0 <= j <= 1000:
                ret += cnt[(i,j)] * cnt[(x,j)] * cnt[(i,y)]
        return ret

# Your DetectSquares object will be instantiated and called as such:
# obj = DetectSquares()
# obj.add(point)
# param_2 = obj.count(point)
# @lc code=end

