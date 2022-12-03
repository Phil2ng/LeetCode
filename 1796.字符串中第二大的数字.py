#
# @lc app=leetcode.cn id=1796 lang=python3
#
# [1796] 字符串中第二大的数字
#

# @lc code=start
class Solution:
    def secondHighest(self, s: str) -> int:
        first, second = -1, -1
        for c in s:
            if c.isdigit():
                t = int(c)
                if first < t:
                    first, second = t, first
                elif second < t < first:
                    second = t
        return second
# @lc code=end

