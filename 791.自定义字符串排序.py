#
# @lc app=leetcode.cn id=791 lang=python3
#
# [791] 自定义字符串排序
#

# @lc code=start
class Solution:
    def customSortString(self, order: str, s: str) -> str:
        cnt = Counter(s) 
        ans = ""
        for c in order:
            if c in cnt:
                ans += c * cnt[c] 
                cnt.pop(c)
        for k, v in cnt.items():
            ans += k * v
        return ans
# @lc code=end

