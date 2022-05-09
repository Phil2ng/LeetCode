#
# @lc app=leetcode.cn id=442 lang=python3
#
# [442] 数组中重复的数据
#


# @lc code=start
class Solution:
    def findDuplicates(self, nums: List[int]) -> List[int]:
        ans = []
        for x in nums:
            x = abs(x)
            if nums[x - 1] > 0:
                nums[x - 1] = -nums[x - 1]
            else:
                ans.append(x)
        return ans
# @lc code=end
