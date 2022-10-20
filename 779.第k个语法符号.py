#
# @lc app=leetcode.cn id=779 lang=python3
#
# [779] 第K个语法符号
#

# @lc code=start
class Solution:
    def kthGrammar(self, n: int, k: int) -> int:
        if n == 1 and k == 1:
            return 0
        return (k & 1) ^ self.kthGrammar(n - 1, k + 1 >> 1) ^ 1
# @lc code=end

