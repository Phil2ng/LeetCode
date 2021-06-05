# 对称性递归

class Solution:
    def mirrorTree(self, root: TreeNode) -> TreeNode:
        if not root:
            return None
        root.left, root.right = self.mirrorTree(
            root.right), self.mirrorTree(root.left)
        return root
