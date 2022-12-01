#
# @lc app=leetcode.cn id=1779 lang=python3
#
# [1779] 找到最近的有相同 X 或 Y 坐标的点
#

# @lc code=start
class Solution:
    def nearestValidPoint(self, x: int, y: int, points: List[List[int]]) -> int:
        ans, pmin = -1, inf 
        for i, (a, b) in enumerate(points):
            if a == x or b == y:
                t = abs(a - x) + abs(b - y) 
                if t < pmin:
                    pmin = t 
                    ans = i  
        return ans
# @lc code=end

