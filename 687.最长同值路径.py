#
# @lc app=leetcode.cn id=687 lang=python3
#
# [687] 最长同值路径
#

# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def longestUnivaluePath(self, root: Optional[TreeNode]) -> int:
        ans = 0

        def helper(root: Optional[TreeNode]):
            if not root:
                return 0
            left = helper(root.left)
            right = helper(root.right)
            ret = t = 0
            if root.left and root.val == root.left.val:
                ret = max(left + 1, ret)
                t += left + 1
            if root.right and root.val == root.right.val:
                ret = max(right + 1, ret)
                t += right + 1
            nonlocal ans
            ans = max(ans, t)
            return ret

        helper(root)
        return ans
# @lc code=end

