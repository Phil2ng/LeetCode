#
# @lc app=leetcode.cn id=1784 lang=python3
#
# [1784] 检查二进制字符串字段
#

# @lc code=start
class Solution:
    def checkOnesSegment(self, s: str) -> bool:
        return '01' not in s
# @lc code=end

