#
# @lc app=leetcode.cn id=1614 lang=python3
#
# [1614] 括号的最大嵌套深度
#
# @lc code=start
class Solution:
    def maxDepth(self, s: str) -> int:
        ans = cnt = 0
        for c in s:
            if c == '(':
                cnt += 1
                ans = max(ans, cnt)
            elif c == ')':
                cnt -= 1
        return ans
# @lc code=end
