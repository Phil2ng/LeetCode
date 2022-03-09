#
# @lc app=leetcode.cn id=798 lang=python3
#
# [798] 得分最高的最小轮调
#

# @lc code=start
class Solution:
    def bestRotation(self, nums: List[int]) -> int:
        n = len(nums)
        arr = [0] * n
        for i, x in enumerate(nums):
            low = (i+1) % n
            high = (i-x+n+1) % n
            arr[low] += 1
            arr[high] -= 1
            if low >= high:
                arr[0] += 1
        psum, pmax, idx = 0, 0, 0
        for i in range(n):
            psum += arr[i]
            if psum > pmax:
                pmax = psum
                idx = i
        return idx
# @lc code=end

