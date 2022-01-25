#
# @lc app=leetcode.cn id=1688 lang=python3
#
# [1688] 比赛中的配对次数
#


# @lc code=start
class Solution:
    def numberOfMatches(self, n: int) -> int:
        ans = 0
        while n != 1:
            yu = n % 2
            ans += n // 2
            n = n // 2 + yu
        return ans
# @lc code=end
