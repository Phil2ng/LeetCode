#
# @lc app=leetcode.cn id=2100 lang=python3
#
# [2100] 适合打劫银行的日子
#

# @lc code=start
class Solution:
    def goodDaysToRobBank(self, security: List[int], time: int) -> List[int]:
        n = len(security)
        a, b, = [0] * n, [0] * n
        ans = []
        for i in range(1, n):
            if security[i] <= security[i - 1]:
                a[i] = a[i - 1] + 1
            if security[n - i - 1] <= security[n - i]:
                b[n - i - 1] = b[n - i] + 1
        for i in range(n):
            if a[i] >= time and b[i] >= time:
                ans.append(security[i])
        return ans
# @lc code=end

