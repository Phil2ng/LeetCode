# 层次遍历

class Solution:
    def levelOrder(self, root: TreeNode) -> List[int]:
        if not root:
            return []
        ans, queue = [], []
        queue.append(root)
        while queue:
            q = queue.pop(0)
            ans.append(q.val)
            if q.left:
                queue.append(q.left)
            if q.right:
                queue.append(q.right)
        return ans
