#
# @lc app=leetcode.cn id=537 lang=python3
#
# [537] 复数乘法
#

# @lc code=start
class Solution:
    def complexNumberMultiply(self, num1: str, num2: str) -> str:
        a, b = map(int, num1[:-1].split('+'))
        c, d = map(int, num2[:-1].split('+'))
        e, f = a*c - b*d, a*d + b*c
        return str(e) + '+' + str(f) + 'i'
# @lc code=end

