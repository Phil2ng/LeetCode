#
# @lc app=leetcode.cn id=1252 lang=python3
#
# [1252] 奇数值单元格的数目
#

# @lc code=start
class Solution:
    def oddCells(self, m: int, n: int, indices: List[List[int]]) -> int:
        row, col = [0] * m, [0] * n
        for x, y in indices:
            row[x] += 1
            col[y] += 1
        r0 = r1 = c0 = c1 = 0
        for i in range(m):
            if row[i] & 1:
                r1 += 1
            else:
                r0 += 1
        for j in range(n):
            if col[j] & 1:
                c1 += 1
            else:
                c0 += 1
        return r0 * c1 + r1 * c0
# @lc code=end

