#
# @lc app=leetcode.cn id=806 lang=python3
#
# [806] 写字符串需要的行数
#

# @lc code=start
class Solution:
    def numberOfLines(self, widths: List[int], s: str) -> List[int]:
        i, L, n, cnt = 0, 0, len(s), cnt
        while i < n:
            if L + widths[ord(s[i]) - ord('a')] > 100:
                L = 0
                cnt += 1
                continue
            L += widths[ord(s[i]) - ord('a')]
            i += 1
        return [cnt, L]
# @lc code=end

