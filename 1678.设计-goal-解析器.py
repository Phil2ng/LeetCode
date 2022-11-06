#
# @lc app=leetcode.cn id=1678 lang=python3
#
# [1678] 设计 Goal 解析器
#

# @lc code=start
class Solution:
    def interpret(self, command: str) -> str:
        ans = ""
        n = len(command)
        i = 0
        while i < n:
            if command[i] != '(' and command[i] != ')':
                ans += command[i]
            elif i + 1 < n and command[i] == '(' and command[i+1] == ')':
                ans += 'o'
            i += 1
        return ans
# @lc code=end

