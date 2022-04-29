#
# @lc app=leetcode.cn id=427 lang=python3
#
# [427] 建立四叉树
#

# @lc code=start
"""
# Definition for a QuadTree node.
class Node:
    def __init__(self, val, isLeaf, topLeft, topRight, bottomLeft, bottomRight):
        self.val = val
        self.isLeaf = isLeaf
        self.topLeft = topLeft
        self.topRight = topRight
        self.bottomLeft = bottomLeft
        self.bottomRight = bottomRight
"""
class Solution:
    def construct(self, grid: List[List[int]]) -> 'Node':
        def all01(x, y, n):
            all0, all1 = 0, 1
            for i in range(x, x + n):
                for j in range(y, y + n):
                    all0 |= grid[i][j]
                    all1 &= grid[i][j]
            if all0 == 0:
                return 0
            if all1 == 1:
                return 1
            return 2

        def helper(x, y, n):
            t = all01(x, y, n)
            if t == 0:
                return Node(False, True, None, None, None, None)
            elif t == 1:
                return Node(True, True, None, None, None, None)
            node = Node(True, False, None, None, None, None)
            n //= 2
            node.topLeft = helper(x, y, n)
            node.topRight = helper(x, y + n, n)
            node.bottomLeft = helper(x + n, y, n)
            node.bottomRight = helper(x + n, y + n, n)
            return node

        n = len(grid)
        return helper(0, 0, n)


# @lc code=end
