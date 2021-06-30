#
# @lc app=leetcode.cn id=1122 lang=python3
#
# 计数排序
#
# [1122] 数组的相对排序
#

# @lc code=start
class Solution:
    def relativeSortArray(self, arr1: List[int], arr2: List[int]) -> List[int]:
        dic = Counter(arr1)
        i = 0
        for num in arr2:
            while dic[num]:
                arr1[i] = num
                i += 1
                dic[num] -= 1
        for j in range(1001):
            while dic[j]:
                arr1[i] = j
                i += 1
                dic[j] -= 1
        return arr1
# @lc code=end
