#
# @lc app=leetcode.cn id=1791 lang=python3
#
# [1791] 找出星型图的中心节点
#


# @lc code=start
class Solution:

    def findCenter(self, edges: List[List[int]]) -> int:
        return edges[0][0] if edges[0][0] == edges[1][0] or edges[0][0] == edges[1][1] else edges[0][1]


# @lc code=end
