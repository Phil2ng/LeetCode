#
# @lc app=leetcode.cn id=917 lang=python3
#
# [917] 仅仅反转字母
#

# @lc code=start
class Solution:
    def reverseOnlyLetters(self, s: str) -> str:
        ls = list(s)
        l, r = 0, len(ls) - 1
        while l < r:
            while l < r and not ls[l].isalpha():
                l += 1
            while l < r and not ls[r].isalpha():
                r -= 1
            if l < r:
                ls[l], ls[r] = ls[r], ls[l]
                l += 1
                r -= 1
        return ''.join(ls)
# @lc code=end

