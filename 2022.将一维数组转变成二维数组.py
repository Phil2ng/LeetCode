#
# @lc app=leetcode.cn id=2022 lang=python3
#
# [2022] 将一维数组转变成二维数组
#

# @lc code=start
class Solution:
    def construct2DArray(self, original: List[int], m: int, n: int) -> List[List[int]]:
        ans = []
        if len(original) != m*n:
            return []
        for i in range(0, len(original),n):
            ans.append(original[i:i+n])
        return ans
# @lc code=end

