#
# @lc app=leetcode.cn id=693 lang=python3
#
# [693] 交替位二进制数
#

# @lc code=start
class Solution:
    def hasAlternatingBits(self, n: int) -> bool:
        t = n % 2
        n //= 2
        while n:
            if t == n % 2:
                return False
            t = n % 2
            n //= 2
        return True
# @lc code=end

