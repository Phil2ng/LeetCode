# 层次遍历

class Solution:
    def levelOrder(self, root: TreeNode) -> List[int]:
        if not root:
            return []
        ans, queue = [], []
        queue.append(root)
        while queue:
            k = len(queue)
            tmp = []
            for _ in range(k):
                q = queue.pop(0)
                tmp.append(q.val)
                if q.left:
                    queue.append(q.left)
                if q.right:
                    queue.append(q.right)
            ans.append(tmp)
        return ans
