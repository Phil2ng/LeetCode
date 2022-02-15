#
# @lc app=leetcode.cn id=1380 lang=python3
#
# [1380] 矩阵中的幸运数
#

# @lc code=start
class Solution:
    def luckyNumbers (self, matrix: List[List[int]]) -> List[int]:
        m, n = len(matrix), len(matrix[0]) if matrix else 0
        row, col = [inf]*m, [-inf]*n
        ans = []
        for i in range(m):
            for j in range(n):
                row[i] = min(row[i], matrix[i][j])
                col[j] = max(col[j], matrix[i][j])
        for i in range(m):
            for j in range(n):
                if matrix[i][j] == row[i] == col[j]:
                    ans.append(matrix[i][j])
        return ans
# @lc code=end

