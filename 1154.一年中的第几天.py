#
# @lc app=leetcode.cn id=1154 lang=python3
#
# [1154] 一年中的第几天
#

# @lc code=start
class Solution:
    def dayOfYear(self, date: str) -> int:
        month = (31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31)
        date = list(map(int, date.split('-')))
        ans = sum(month[:date[1] - 1]) + date[2]
        if date[0] % 4 == 0 and date[0] % 100 or date[0] % 400 == 0:
            if date[1] > 2:
                ans += 1
        return ans
# @lc code=end

