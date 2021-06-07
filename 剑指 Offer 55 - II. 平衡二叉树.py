# 递归

class Solution:
    def isBalanced(self, root: TreeNode) -> bool:
        def depth(root: TreeNode):
            if not root:
                return 0
            left = depth(root.left)
            if left == -1:
                return -1
            right = depth(root.right)
            if right == -1:
                return -1
            if abs(left-right) <= 1:
                return max(left, right)+1
            else:
                return -1
        ans = depth(root)
        return False if ans == -1 else True
