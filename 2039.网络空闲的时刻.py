#
# @lc app=leetcode.cn id=2039 lang=python3
#
# [2039] 网络空闲的时刻
#

# @lc code=start
class Solution:
    def networkBecomesIdle(self, edges: List[List[int]], patience: List[int]) -> int:
        n = len(patience)
        neighbor = [[] for _ in range(n)]
        seen = [False] * n
        for u, v in edges:
            neighbor[u].append(v)
            neighbor[v].append(u)
        seen[0] = True
        que = deque([0])
        ans, dist = 0, 0
        while que:
            dist += 1
            for _ in range(len(que)):
                u = que.popleft()
                for v in neighbor[u]:
                    if seen[v]:
                        continue
                    seen[v] = True
                    que.append(v)
                    ans = max(ans, 2*dist + (2*dist - 1) // patience[v] * patience[v])
        return ans + 1

# @lc code=end

