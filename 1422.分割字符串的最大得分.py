#
# @lc app=leetcode.cn id=1422 lang=python3
#
# [1422] 分割字符串的最大得分
#

# @lc code=start
class Solution:
    def maxScore(self, s: str) -> int:
        left, right = [], []
        cnt0, cnt1 = 0, 0
        n = len(s)
        for i in range(n):
            if s[i] == '0':
                cnt0 += 1
            if s[n-1-i] == '1':
                cnt1 += 1
            left.append(cnt0)
            right.append(cnt1)
        ans = 0
        for i in range(n - 1) :
            ans = max(ans, left[i] + right[n-2-i])
        return ans

# @lc code=end

