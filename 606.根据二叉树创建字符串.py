#
# @lc app=leetcode.cn id=606 lang=python3
#
# [606] 根据二叉树创建字符串
#

# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def tree2str(self, root: Optional[TreeNode]) -> str:
        if not root:
            return ""
        ret = str(root.val)
        if root.right or root.left:
            ret += '(' + self.tree2str(root.left) + ')'
        if root.right:
            ret += '(' + self.tree2str(root.right) + ')'
        return ret
# @lc code=end

