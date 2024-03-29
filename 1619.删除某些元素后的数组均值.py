#
# @lc app=leetcode.cn id=1619 lang=python3
#
# [1619] 删除某些元素后的数组均值
#

# @lc code=start
class Solution:
    def trimMean(self, arr: List[int]) -> float:
        arr.sort()
        t = len(arr) // 20
        return sum(arr[t:-t]) / (len(arr)-2*t)
# @lc code=end

