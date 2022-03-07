#
# @lc app=leetcode.cn id=504 lang=python3
#
# [504] 七进制数
#


# @lc code=start
class Solution:
    def convertToBase7(self, num: int) -> str:
        if num == 0:
            return "0"
        sign = -1 if num < 0 else 1
        x = abs(num)
        ans = ""
        while x:
            ans = str(x % 7) + ans
            x //= 7
        if sign < 0:
            ans = "-" + ans
        return ans
# @lc code=end
