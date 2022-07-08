#
# @lc app=leetcode.cn id=1217 lang=python3
#
# [1217] 玩筹码
#

# @lc code=start
class Solution:
    def minCostToMoveChips(self, position: List[int]) -> int:
        cnt0, cnt1 = 0, 0
        for x in position:
            if x & 1 :
                cnt1 += 1
            else:
                cnt0 += 1
        return min(cnt0, cnt1)
# @lc code=end

