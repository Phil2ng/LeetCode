#
# @lc app=leetcode.cn id=2104 lang=python3
#
# [2104] 子数组范围和
#

# @lc code=start
class Solution:
    def subArrayRanges(self, nums: List[int]) -> int:
        ans, n = 0, len(nums)
        for i in range(n):
            pmin, pmax = inf, -inf
            for j in range(i, n):
                pmin = min(pmin, nums[j])
                pmax = min(pmax, nums[j])
                ans += pmax - pmin
        return ans
# @lc code=end

