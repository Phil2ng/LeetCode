# DFS

class Solution:
    def pathSum(self, root: TreeNode, target: int) -> List[List[int]]:
        ans, path = [], []

        def dfs(root, sum):
            if not root:
                return
            sum += root.val
            path.append(root.val)
            if sum == target and not root.left and not root.right:
                ans.append(list(path))
            dfs(root.left, sum)
            dfs(root.right, sum)
            sum -= root.val
            path.pop()

        dfs(root, 0)
        return ans
