#
# @lc app=leetcode.cn id=688 lang=python3
#
# [688] 骑士在棋盘上的概率
#


# @lc code=start
class Solution:

    def knightProbability(self, n: int, k: int, row: int, column: int) -> float:
        direction = ((-2, -1), (-2, 1), (2, -1), (2, 1), (-1, -2), (-1, 2), (1, -2), (1, 2))
        dp = [[[1] * n for _ in range(n)] for _ in range(k + 1)]
        for step in range(1, k + 1):
            for i in range(n):
                for j in range(n):
                    for dx, dy in direction:
                        x, y = i + dx, j + dy
                        if 0 <= x < n and 0 <= y < n:
                            dp[step][i][j] += dp[step - 1][x][y] / 8
        return dp[k][row][column]


# @lc code=end
