#
# @lc app=leetcode.cn id=773 lang=python3
#
# BFS
#
# [773] 滑动谜题
#

# @lc code=start
class Solution:
    direction = [-1, 0, 1, 0, -1]

    def slidingPuzzle(self, board: List[List[int]]) -> int:
        m, n = len(board), len(board[0])
        dic = {((1, 2, 3), (4, 5, 0)): 0}
        que = collections.deque()
        que.append(((1, 2, 3), (4, 5, 0)))

        def find0(l):
            for i in range(m):
                for j in range(n):
                    if l[i][j] == 0:
                        return (i, j)

        def move(l, step):
            i, j = find0(l)
            for k in range(4):
                x, y = i+self.direction[k], j+self.direction[k+1]
                if 0 <= x < m and 0 <= y < n:
                    l[i][j], l[x][y] = l[x][y], l[i][j]
                    tp = tuple(map(tuple, l))
                    if tp not in dic:
                        dic[tp] = step+1
                        que.append(tp)
                    l[i][j], l[x][y] = l[x][y], l[i][j]

        while que:
            t = que.popleft()
            step = dic[t]
            l = list(map(list, t))
            move(l, step)

        b = tuple(map(tuple, board))
        if b not in dic:
            return -1
        return dic[b]
# @lc code=end
