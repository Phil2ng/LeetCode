
class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        ans = root
        while True:
            if p.val < ans.val and q.val < ans.val:
                ans = ans.left
            elif p.val > ans.val and q.val > ans.val:
                ans = ans.right
            else:
                break
        return ans
