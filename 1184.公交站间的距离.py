#
# @lc app=leetcode.cn id=1184 lang=python3
#
# [1184] 公交站间的距离
#

# @lc code=start
class Solution:
    def distanceBetweenBusStops(self, distance: List[int], start: int,
                                destination: int) -> int:
        dist = 0
        i = start
        n = len(distance)
        while i != destination:
            dist += distance[i]
            i = (i + 1) % n
        return min(dist, sum(distance) - dist)
# @lc code=end

