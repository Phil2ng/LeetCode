# DFS遍历

class Solution:
    def kthLargest(self, root: TreeNode, k: int) -> int:
        def dfs(root):
            if not root or self.k == 0:
                return
            dfs(root.right)
            self.k -= 1
            if self.k == 0:
                self.ans = root.val
            dfs(root.left)

        self.k = k
        dfs(root)
        return self.ans

# class Solution:
#     def kthLargest(self, root: TreeNode, k: int) -> int:
#         def dfs(root):
#             if not root:
#                 return []
#             return dfs(root.right)+[root.val]+dfs(root.left)

#         ans = dfs(root)
#         return ans[k-1]
