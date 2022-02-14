#
# @lc app=leetcode.cn id=540 lang=python3
#
# [540] 有序数组中的单一元素
#

# @lc code=start
class Solution:
    def singleNonDuplicate(self, nums: List[int]) -> int:
        left, right = 0, len(nums) - 1
        while left < right:
            mid = left + right >> 1
            if mid % 2:
                if nums[mid] == nums[mid - 1]:
                    left = mid + 1
                else:
                    right = mid - 1
            else:
                if nums[mid] == nums[mid + 1]:
                    left = mid + 2
                else:
                    right = mid
        return nums[left]
# @lc code=end

