#
# @lc app=leetcode.cn id=944 lang=python3
#
# [944] 删列造序
#

# @lc code=start
class Solution:
    def minDeletionSize(self, strs: List[str]) -> int:
        ans = 0
        m, n = len(strs), len(strs[0])
        for j in range(n):
            c = 'a'
            for i in range(m):
                if strs[i][j] < c:
                    ans += 1
                    break
                c = strs[i][j]
        return ans

# @lc code=end

