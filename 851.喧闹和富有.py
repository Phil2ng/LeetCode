#
# @lc app=leetcode.cn id=851 lang=python3
#
# 拓扑排序
#
# [851] 喧闹和富有
#

# @lc code=start
class Solution:
    def loudAndRich(self, richer: List[List[int]], quiet: List[int]) -> List[int]:
        n = len(quiet)
        road = [[] for _ in range(n)]
        inDeg = [0]*n
        for r in richer:
            road[r[0]].append(r[1])
            inDeg[r[1]]+=1
        ans = list(range(n))
        q = deque(i for i,deg in enumerate(inDeg) if deg==0)
        while q:
            x = q.popleft()
            for y in road[x]:
                if quiet[ans[x]] < quiet[ans[y]]:
                    ans[y] = ans[x]
                inDeg[y]-=1
                if inDeg[y]==0:
                    q.append(y)
        return ans
# @lc code=end

