#
# @lc app=leetcode.cn id=1606 lang=python3
#
# [1606] 找到处理最多请求的服务器
#

# @lc code=start
from sortedcontainers import SortedList


class Solution:
    def busiestServers(self, k: int, arrival: List[int], load: List[int]) -> List[int]:
        n = len(arrival)
        available = SortedList(range(k))
        busy = []
        cnt = [0] * k
        for i in range(n):
            while busy and busy[0][0] <= arrival[i]:
                _, id = heappop(busy)
                available.add(id)
            if len(available) == 0:
                continue
            t = available.bisect_left(i % k)
            if t == len(available):
                t = 0
            id = available[t]
            heappush(busy, (arrival[i] + load[i], id)) 
            cnt[id] += 1
            available.remove(id)

        pmax = max(cnt)
        return [i for i in range(k) if cnt[i] == pmax]


# @lc code=end

