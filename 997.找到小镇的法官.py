#
# @lc app=leetcode.cn id=997 lang=python3
#
# [997] 找到小镇的法官
#


# @lc code=start
class Solution:
    def findJudge(self, n: int, trust: List[List[int]]) -> int:
        inDegrees = Counter(y for _, y in trust)
        outDegrees = Counter(x for x, _ in trust)
        return next((i for i in range(1, n + 1)
                     if inDegrees[i] == n - 1 and outDegrees[i] == 0), -1)


# @lc code=end
