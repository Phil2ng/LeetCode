#
# @lc app=leetcode.cn id=658 lang=python3
#
# [658] 找到 K 个最接近的元素
#

# @lc code=start
class Solution:
    def findClosestElements(self, arr: List[int], k: int, x: int) -> List[int]:
        n = len(arr)
        r = bisect_left(arr, x)
        l = r - 1
        while k:
            if l < 0 or r < n and arr[r] - x < x - arr[l]:
                r += 1
            else:
                l -= 1
            k -= 1
        return arr[l+1 : r]
# @lc code=end

