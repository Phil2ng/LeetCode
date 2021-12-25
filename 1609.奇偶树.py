#
# @lc app=leetcode.cn id=1609 lang=python3
#
# BFS/层序遍历
#
# [1609] 奇偶树
#

# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isEvenOddTree(self, root: Optional[TreeNode]) -> bool:
        if root.val%2==0:
            return False
        que = deque()
        que.append(root)
        t = 0

        def less(a, b, t):
            print(a,b,t)
            if t % 2:
                return a > b
            return a < b

        while que:
            t += 1
            n = len(que)
            flag = False
            for _ in range(n):
                q = que.popleft()
                print(q.val)
                if q.left:
                    if (q.left.val%2 ^ t%2) == 0:
                        return False
                    if flag:
                        if not less(que[-1].val, q.left.val, t):
                            return False
                    que.append(q.left)
                    flag = True
                if q.right:
                    if (q.right.val%2 ^ t%2) == 0:
                        return False
                    if flag:
                        if not less(que[-1].val, q.right.val, t):
                            return False
                    que.append(q.right)
                    flag = True
        return True
# @lc code=end

