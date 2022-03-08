#
# @lc app=leetcode.cn id=2055 lang=python3
#
# [2055] 蜡烛之间的盘子
#

# @lc code=start
class Solution:
    def platesBetweenCandles(self, s: str, queries: List[List[int]]) -> List[int]:
        n, t = len(s), 0
        left, right = [0] * n, [0] * n
        for i, c in enumerate(s):
            if c == '|':
                left[i] = t
            else:
                t += 1
                left[i] = left[i - 1]
        for i in range(n - 1, -1, -1):
            if s[i] == '|':
                t = left[i]
            right[i] = t
        ans = []
        for l, r in queries:
            ans.append(max(0, left[r] - right[l]))
        return ans
# @lc code=end

