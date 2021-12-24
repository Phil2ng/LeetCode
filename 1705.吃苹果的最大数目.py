#
# @lc app=leetcode.cn id=1705 lang=python3
# 
# 优先队列
# 
# [1705] 吃苹果的最大数目
#

# @lc code=start
class Solution:
    def eatenApples(self, apples: List[int], days: List[int]) -> int:
        ans, i, n, max_day = 0, 0, len(apples), len(apples) + max(days)
        pq = []
        while i < max_day:
            while pq and (pq[0][0] <= i or pq[0][1] == 0):
                heapq.heappop(pq)
            if i < n and apples[i]:
                heapq.heappush(pq, [i + days[i], apples[i]])
            if pq:
                pq[0][1] -= 1
                ans += 1
            i += 1
        return ans
# @lc code=end

