#
# @lc app=leetcode.cn id=1624 lang=python3
#
# [1624] 两个相同字符之间的最长子字符串
#

# @lc code=start
class Solution:
    def maxLengthBetweenEqualCharacters(self, s: str) -> int:
        idx = {}
        ans = -1
        for i, c in enumerate(s):
            if c in idx:
                ans = max(ans, i - idx[c] - 1)
            else:
                idx[c] = i
        return ans
# @lc code=end

