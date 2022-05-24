#
# @lc app=leetcode.cn id=965 lang=python3
#
# [965] 单值二叉树
#

# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isUnivalTree(self, root: TreeNode) -> bool:
        if not root:
            return True
        
        if root.left:
            if root.val != root.left.val or not self.isUnivalTree(root.left):
                return False
        
        if root.right:
            if root.val != root.right.val or not self.isUnivalTree(root.right):
                return False
        
        return True

# @lc code=end

