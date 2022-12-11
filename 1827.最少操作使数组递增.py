#
# @lc app=leetcode.cn id=1827 lang=python3
#
# [1827] 最少操作使数组递增
#

# @lc code=start
class Solution:
    def minOperations(self, nums: List[int]) -> int:
        pre = -inf
        ans = 0
        for i in range(len(nums)):
            ans += max(0, pre - nums[i] + 1)
            pre = max(pre + 1, nums[i])
        return ans
# @lc code=end

