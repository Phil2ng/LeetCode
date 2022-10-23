#
# @lc app=leetcode.cn id=1768 lang=python3
#
# [1768] 交替合并字符串
#

# @lc code=start
class Solution:
    def mergeAlternately(self, word1: str, word2: str) -> str:
        ans = ""
        i, m, n = 0, len(word1), len(word2)
        while i < m and i < n:
            ans += word1[i] + word2[i]
            i += 1
        while i < m:
            ans += word1[i]
            i += 1
        while i < n:
            ans += word2[i]
            i += 1
        return ans
# @lc code=end

