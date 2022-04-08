#
# @lc app=leetcode.cn id=429 lang=python3
#
# [429] N 叉树的层序遍历
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
    def levelOrder(self, root: 'Node') -> List[List[int]]:
        if not root:
            return []
        que = deque([root])
        ans = []
        while que:
            tmp = []
            for _ in range(len(que)):
                node = que.popleft()
                tmp.append(node.val)
                for child in node.children:
                    que.append(child)
            ans.append(tmp[:])
        return ans
        
# @lc code=end

