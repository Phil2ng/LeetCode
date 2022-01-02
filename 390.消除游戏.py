#
# @lc app=leetcode.cn id=390 lang=python3
#
# [390] 消除游戏
#

# @lc code=start
class Solution:
    def lastRemaining(self, n: int) -> int:
        ans, k, cnt, step = 1, 0, n, 1
        while cnt > 1:
            if k % 2 == 0:
                ans += step
            else:
                if cnt % 2:
                    ans += step
            k, cnt, step = k+1, cnt>>1, step<<1
        return ans
# @lc code=end

