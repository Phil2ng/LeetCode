#
# @lc app=leetcode.cn id=1020 lang=python3
#
# [1020] 飞地的数量
#


# @lc code=start
class Solution:
    def numEnclaves(self, grid: List[List[int]]) -> int:
        # 找出边界陆地; dfs所有联通的陆地; 统计剩余陆地数目
        m, n = len(grid), len(grid[0]) if grid else 0
        direction = [-1, 0, 1, 0, -1]
        ans = 0

        def dfs(row: int, col: int):
            grid[row][col] = 0
            for i in range(4):
                x, y = row + direction[i], col + direction[i + 1]
                if 0 <= x < m and 0 <= y < n and grid[x][y] == 1:
                    dfs(x, y)

        for i in range(m):
            for j in range(n):
                if (i == 0 or i == m - 1 or j == 0
                        or j == n - 1) and grid[i][j] == 1:
                    dfs(i, j)
        for i in range(m):
            for j in range(n):
                if grid[i][j] == 1:
                    ans += 1
        return ans
# @lc code=end
