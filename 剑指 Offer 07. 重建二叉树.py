# 三序遍历构建二叉树

class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> TreeNode:
        if not preorder:
            return None
        head = TreeNode(preorder[0])
        t = inorder.index(preorder[0])
        head.left = self.buildTree(preorder[1:t+1], inorder[:t])
        head.right = self.buildTree(preorder[t+1:], inorder[t+1:])
        return head
