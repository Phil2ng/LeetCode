#
# @lc app=leetcode.cn id=310 lang=python3
#
# [310] 最小高度树
#

# @lc code=start
class Solution:
    def findMinHeightTrees(self, n: int, edges: List[List[int]]) -> List[int]:
        nei = [[] for _ in range(n)]
        cnt = [0] * n
        for a, b in edges:
            nei[a].append(b)
            nei[b].append(a)
            cnt[a] += 1
            cnt[b] += 1
        que = []
        for i in range(n):
            if cnt[i] == 1:
                que.append(i)
        ans = [0]
        while que:
            ans = que
            que = []
            for a in ans:
                for b in nei[a]:
                    cnt[b] -= 1
                    if cnt[b] == 1:
                        que.append(b)
        return ans
# @lc code=end

