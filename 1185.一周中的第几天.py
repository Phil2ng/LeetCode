#
# @lc app=leetcode.cn id=1185 lang=python3
#
# [1185] 一周中的第几天
#

# @lc code=start
class Solution:
    def dayOfTheWeek(self, day: int, month: int, year: int) -> str:
        return datetime.date(year, month, day).strftime('%A')
# @lc code=end

