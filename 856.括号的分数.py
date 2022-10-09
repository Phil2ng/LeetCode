#
# @lc app=leetcode.cn id=856 lang=python3
#
# [856] 括号的分数
#

# @lc code=start
class Solution:
    def scoreOfParentheses(self, s: str) -> int:
        ans = bal = 0
        for i, c in enumerate(s):
            bal += 1 if c == '(' else -1
            if c == ')' and s[i-1] == '(':
                ans += 1 << bal
        return ans
# @lc code=end

