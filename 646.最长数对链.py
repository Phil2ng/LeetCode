#
# @lc app=leetcode.cn id=646 lang=python3
#
# [646] 最长数对链
#

# @lc code=start
class Solution:
    def findLongestChain(self, pairs: List[List[int]]) -> int:
        pairs.sort(key=lambda x: x[1])
        ans = 0
        p = -inf
        for a,b in pairs:
            if p < a:
                ans += 1
                p = b
        return ans
# @lc code=end

