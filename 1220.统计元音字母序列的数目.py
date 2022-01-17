#
# @lc app=leetcode.cn id=1220 lang=python3
#
# [1220] 统计元音字母序列的数目
#

# @lc code=start
class Solution:
    def countVowelPermutation(self, n: int) -> int:
        dic = {
            'end': ['a', 'e', 'i', 'o', 'u'],
            'a': ['e', 'i', 'u'],
            'e': ['a', 'i'],
            'i': ['e', 'o'],
            'o': ['i'],
            'u': ['i', 'o']
        }
        mod = 10**9 + 7

        @lru_cache(None)
        def dp(step: int, status: str):
            if step == 0:
                return 1
            ret = 0
            for c in dic[status]:
                ret = (ret + dp(step - 1, c)) % mod
            return ret

        return dp(n, 'end')
# @lc code=end

