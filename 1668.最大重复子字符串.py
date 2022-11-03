#
# @lc app=leetcode.cn id=1668 lang=python3
#
# [1668] 最大重复子字符串
#

# @lc code=start
class Solution:
    def maxRepeating(self, sequence: str, word: str) -> int:
        n, m = len(sequence), len(word)
        if n < m:
            return 0
        
        f = [0] * n
        for i in range(m - 1, n):
            valid = True
            for j in range(m):
                if sequence[i - m + j + 1] != word[j]:
                    valid = False
                    break
            if valid:
                f[i] = (0 if i < m else f[i - m]) + 1
        
        return max(f)
# @lc code=end

