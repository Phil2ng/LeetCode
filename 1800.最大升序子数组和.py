#
# @lc app=leetcode.cn id=1800 lang=python3
#
# [1800] 最大升序子数组和
#

# @lc code=start
class Solution:
    def maxAscendingSum(self, nums: List[int]) -> int:
        ans, t, pre = 0, 0, inf
        for x in nums:
            if x > pre:
                t += x
            else:
                t = x
            ans = max(ans, t)
            pre = x
        return ans
# @lc code=end

