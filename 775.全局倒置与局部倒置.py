#
# @lc app=leetcode.cn id=775 lang=python3
#
# [775] 全局倒置与局部倒置
#

# @lc code=start
from sortedcontainers import SortedList
class Solution:
    def isIdealPermutation(self, nums: List[int]) -> bool:
        cnt1 = cnt2 = 0
        n = len(nums)
        arr = SortedList() 
        for i in range(n-1, -1, -1):
            arr.add(nums[i])
            cnt1 += arr.index(nums[i])
        for i in range(n - 1):
            if nums[i] > nums[i + 1]:
                cnt2 += 1
        return cnt1 == cnt2
# @lc code=end

