# BST二叉搜索树的性质, 辅助单调栈

class Solution:
    def treeToDoublyList(self, root: 'Node') -> 'Node':
        if not root:
            return
        stack = [root]
        while stack[-1].left:
            stack.append(stack[-1].left)
        head = pre = stack.pop()
        while True:
            if pre.right:
                stack.append(pre.right)
                while stack[-1].left:
                    stack.append(stack[-1].left)
            if not stack:
                break
            cur = stack.pop()
            pre.right = cur
            cur.left = pre
            pre = cur
        pre.right = head
        head.left = pre
        return head
