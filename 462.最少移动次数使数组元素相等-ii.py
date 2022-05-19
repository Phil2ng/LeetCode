#
# @lc app=leetcode.cn id=462 lang=python3
#
# [462] 最少移动次数使数组元素相等 II
#

# @lc code=start
class Solution:
    def minMoves2(self, nums: List[int]) -> int:
        nums.sort()
        t = nums[len(nums)//2]
        ans = 0
        for x in nums:
            ans += abs(t - x)
        return ans
# @lc code=end

