#
# @lc app=leetcode.cn id=2049 lang=python3
#
# [2049] 统计最高分的节点数目
#


# @lc code=start
class Solution:
    def countHighestScoreNodes(self, parents: List[int]) -> int:
        n = len(parents)
        children = [[] for _ in range(n)]
        for i in range(1, n):
            children[parents[i]].append(i)
        maxScore, count = 0, 0

        def dfs(node: int):
            score, size = 1, 1
            for child in children[node]:
                sz = dfs(child)
                score *= sz
                size += sz
            if node:
                score *= n - size

            nonlocal maxScore, count
            if maxScore < score:
                maxScore, count = score, 1
            elif maxScore == score:
                count += 1
            return size

        dfs(0)
        return count


# @lc code=end
