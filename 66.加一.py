#
# @lc app=leetcode.cn id=66 lang=python3
#
# [66] 加一
#

# @lc code=start
class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        n, p = len(digits), 1
        for i in range(-1, -n-1, -1):
            p, digits[i]= (digits[i] + p ) // 10, (digits[i] + p ) % 10
        if p:
            digits.insert(0, p)
        return digits
# @lc code=end

