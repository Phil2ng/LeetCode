#
# @lc app=leetcode.cn id=1582 lang=python3
#
# [1582] 二进制矩阵中的特殊位置
#

# @lc code=start
class Solution:
    def numSpecial(self, mat: List[List[int]]) -> int:
        rows_sum = [sum(row) for row in mat]
        cols_sum = [sum(col) for col in zip(*mat)]
        ans = 0
        for i, row in enumerate(mat):
            for j, x in enumerate(row):
                if x == 1 and rows_sum[i] == 1 and cols_sum[j] == 1:
                    ans += 1
        return ans
# @lc code=end

