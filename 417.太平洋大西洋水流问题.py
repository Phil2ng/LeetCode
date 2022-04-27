#
# @lc app=leetcode.cn id=417 lang=python3
#
# [417] 太平洋大西洋水流问题
#

# @lc code=start
class Solution:
    def pacificAtlantic(self, heights: List[List[int]]) -> List[List[int]]:
        m, n = len(heights), len(heights[0]) if heights else 0
        direction = [-1, 0, 1, 0, -1]

        def bfs(que: deque):
            ret = set()
            while que:
                row, col = que.popleft()
                ret.add((row, col))
                for i in range(4):
                    x, y = row + direction[i], col + direction[i + 1]
                    if 0 <= x < m and 0 <= y < n and (x, y) not in seen and heights[x][y] >= heights[row][col]:
                        seen.add((x, y))
                        que.append((x, y))
            return ret

        que = deque()
        seen = set()
        for i in range(m):
            seen.add((i, 0))
            que.append((i, 0))
        for j in range(1, n):
            seen.add((0, j))
            que.append((0, j))
        pacific = bfs(que)

        que = deque()
        seen = set()
        for i in range(m):
            seen.add((i, n - 1))
            que.append((i, n - 1))
        for j in range(n - 1):
            seen.add((m - 1, j))
            que.append((m - 1, j))
        atlantic = bfs(que)

        ans = pacific & atlantic
        return [[x, y] for x, y in ans]
# @lc code=end

