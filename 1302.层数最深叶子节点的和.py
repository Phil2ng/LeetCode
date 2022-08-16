#
# @lc app=leetcode.cn id=1302 lang=python3
#
# [1302] 层数最深叶子节点的和
#

# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def deepestLeavesSum(self, root: Optional[TreeNode]) -> int:
        que = deque([root])
        psum = 0
        while que:
            psum = 0
            for _ in range(len(que)):
                node = que.popleft()
                psum += node.val
                if node.left:
                    que.append(node.left)
                if node.right:
                    que.append(node.right)
        return psum
# @lc code=end

