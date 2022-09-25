#
# @lc app=leetcode.cn id=788 lang=python3
#
# [788] 旋转数字
#

# @lc code=start
class Solution:
    def rotatedDigits(self, n: int) -> int:
        a, b = [0,1,2,5,6,8,9], [2,5,6,9]
        def fun(x: int)->bool:
            p = False
            while x:
                y = x % 10
                if y not in a:
                    return False
                if y in b:
                    p = True
                x //= 10
            return p
        ans = 0
        for i in range(1, n+1):
            if fun(i):
                ans += 1
        return ans
# @lc code=end

