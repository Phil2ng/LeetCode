#
# @lc app=leetcode.cn id=821 lang=python3
#
# [821] 字符的最短距离
#

# @lc code=start
class Solution:
    def shortestToChar(self, s: str, c: str) -> List[int]:
        n = len(s)
        ans = [n] * n
        t = -n
        for i in range(-1, -n - 1, -1):
            if c == s[i]:
                t = i
            ans[i] = min(ans[i], abs(t - i))
        t = n + t
        for i in range(n):
            if c == s[i]:
                t = i
            ans[i] = min(ans[i], abs(t - i))
        return ans
# @lc code=end

