#
# @lc app=leetcode.cn id=1413 lang=python3
#
# [1413] 逐步求和得到正数的最小值
#


# @lc code=start
class Solution:
    def minStartValue(self, nums: List[int]) -> int:
        ans, psum = -inf, 1
        for x in nums:
            psum -= x
            ans = max(ans, psum)
        return max(ans, 1)


# @lc code=end
