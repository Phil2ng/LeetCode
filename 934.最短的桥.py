#
# @lc app=leetcode.cn id=934 lang=python3
#
# [934] 最短的桥
#

# @lc code=start
class Solution:
    def shortestBridge(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0]) if grid else 0
        direction = [-1, 0, 1, 0, -1]
        for i in range(m):
            for j in range(n):
                if grid[i][j] != 1:
                    continue
                grid[i][j] = -1
                que = deque([(i, j)])
                island = deque()
                while que:
                    row, col = que.popleft()
                    island.append((row, col))
                    for i in range(4):
                        x, y = row + direction[i], col + direction[i + 1]
                        if 0 <= x < m and 0 <= y < n and grid[x][y] == 1:
                            que.append((x, y))
                            grid[x][y] = -1

                que = island
                step = 0
                while True:
                    for _ in range(len(que)):
                        row, col = que.popleft()
                        for i in range(4):
                            x, y = row + direction[i], col + direction[i + 1]
                            if 0 <= x < m and 0 <= y < n:
                                if grid[x][y] == 1:
                                    return step
                                elif grid[x][y] == 0:
                                    que.append((x, y))
                                    grid[x][y] = -1
                    step += 1
# @lc code=end

