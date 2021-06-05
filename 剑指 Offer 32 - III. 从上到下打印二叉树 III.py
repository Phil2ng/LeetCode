# 层次遍历

class Solution:
    def levelOrder(self, root: TreeNode) -> List[int]:
        if not root:
            return []
        ans, queue = [], []
        queue.append(root)
        while queue:
            n = len(queue)
            tmp = []
            deque = []
            for _ in range(n):
                node = queue.pop(0)
                tmp.append(node.val)
                if node.left:
                    deque.append(node.left)
                if node.right:
                    deque.append(node.right)
            if len(ans) % 2 == 1:
                tmp = tmp[::-1]
            ans.append(tmp)
            queue = deque
        return ans
