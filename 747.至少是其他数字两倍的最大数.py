#
# @lc app=leetcode.cn id=747 lang=python3
#
# [747] 至少是其他数字两倍的最大数
#

# @lc code=start
class Solution:
    def dominantIndex(self, nums: List[int]) -> int:
        pmax = max(nums)//2
        ans = -1
        for i in range(len(nums)):
            if nums[i] > pmax:
                if ans<0:
                    ans = i
                else:
                    return -1
        return ans                

# @lc code=end

