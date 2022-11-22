#
# @lc app=leetcode.cn id=878 lang=python3
#
# [878] 第 N 个神奇数字
#

# @lc code=start
class Solution:
    def nthMagicalNumber(self, n: int, a: int, b: int) -> int:
        n -= 1
        add = []
        ta = tb = 1
        while ta <= b and tb <= a:
            if ta * a < tb * b:
                add.append(ta * a)
                ta += 1
            elif ta * a == tb * b:
                add.append(ta * a)
                ta += 1
                tb += 1
            else:
                add.append(tb * b)
                tb += 1

        i, j = n // len(add), n % len(add)
        mod = 10**9 + 7
        ans = (a * b * i + add[j]) % mod
        return ans
# @lc code=end

