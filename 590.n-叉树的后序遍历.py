#
# @lc app=leetcode.cn id=590 lang=python3
#
# [590] N 叉树的后序遍历
#

# @lc code=start
"""
# Definition for a Node.
class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children
"""


class Solution:
    def postorder(self, root: 'Node') -> List[int]:
        # def dfs(node: 'Node'):
        #     if not node:
        #         return []
        #     ret = []
        #     for child in node.children:
        #         ret += dfs(child)
        #     ret.append(node.val)
        #     return ret
        # return dfs(root)

        ans, stk = [], [root]
        while stk:
            node = stk.pop()
            if node:
                ans.append(node.val)
                stk.extend(node.children)
        ans.reverse()
        return ans


# @lc code=end
