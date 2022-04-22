#
# @lc app=leetcode.cn id=396 lang=python3
#
# [396] 旋转函数
#

# @lc code=start
class Solution:
    def maxRotateFunction(self, nums: List[int]) -> int:
        n = len(nums)
        psum = 0
        for i, x in enumerate(nums):
            psum += i * x
        ans = psum
        m = sum(nums)
        for i in range(n):
            psum = psum + m - n * (nums[n - 1 - i])
            ans = max(ans, psum)
        return ans
# @lc code=end

