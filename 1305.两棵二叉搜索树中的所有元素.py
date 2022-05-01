#
# @lc app=leetcode.cn id=1305 lang=python3
#
# [1305] 两棵二叉搜索树中的所有元素
#

# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def getAllElements(self, root1: TreeNode, root2: TreeNode) -> List[int]:
        def inorder(root, arr):
            if root:
                inorder(root.left, arr)
                arr.append(root.val)
                inorder(root.right, arr)

        arr1, arr2 = [], []
        inorder(root1, arr1)
        inorder(root2, arr2)

        ans = []
        p1, p2, n1, n2 = 0, 0, len(arr1), len(arr2)
        while p1 < n1 and p2 < n2:
            if arr1[p1] < arr2[p2]:
                ans.append(arr1[p1])
                p1 += 1
            else:
                ans.append(arr2[p2])
                p2 += 1
        ans.extend(arr1[p1:])
        ans.extend(arr2[p2:])
        return ans
        
# @lc code=end

