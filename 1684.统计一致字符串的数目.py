#
# @lc app=leetcode.cn id=1684 lang=python3
#
# [1684] 统计一致字符串的数目
#

# @lc code=start
class Solution:
    def countConsistentStrings(self, allowed: str, words: List[str]) -> int:
        def str2int(s: str):
            ret = 0
            for c in s:
                ret |= 1 << ord(c) - ord('a')
            return ret
        pivot = str2int(allowed)
        ans = 0
        for w in words:
            ans += pivot | str2int(w) == pivot
        return ans
# @lc code=end

