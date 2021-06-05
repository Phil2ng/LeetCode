# 对称性递归

class Solution:
    def isSymmetric(self, root: TreeNode) -> bool:
        def recur(L: TreeNode, R: TreeNode):
            if not L and not R:
                return True
            if not L or not R:
                return False
            return L.val == R.val and recur(L.left, R.right) and recur(L.right, R.left)

        return recur(root, root)
