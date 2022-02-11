#
# @lc app=leetcode.cn id=1984 lang=python3
#
# [1984] 学生分数的最小差值
#

# @lc code=start
class Solution:
    def minimumDifference(self, nums: List[int], k: int) -> int:
        nums.sort()
        return min(nums[i] - nums[i-k+1] for i in range(k-1, len(nums)))
# @lc code=end

