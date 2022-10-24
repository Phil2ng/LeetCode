#
# @lc app=leetcode.cn id=915 lang=python3
#
# [915] 分割数组
#

# @lc code=start
class Solution:
    def partitionDisjoint(self, nums: List[int]) -> int:
        n = len(nums)
        arr = nums[:]
        for i in range(n-2, -1, -1):
            arr[i] = min(arr[i], arr[i+1])
        pmax = -inf
        for i in range(1, n):
            pmax = max(pmax, nums[i - 1])
            if pmax <= arr[i]:
                return i
        return -1
# @lc code=end

