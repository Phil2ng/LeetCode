#
# @lc app=leetcode.cn id=799 lang=python3
#
# [799] 香槟塔
#

# @lc code=start
class Solution:
    def champagneTower(self, poured: int, query_row: int, query_glass: int) -> float:
        row = [poured] 
        for i in range(1, query_row + 1):
            nxt = [0] * (i + 1) 
            for j, v in enumerate(row):
                if v > 1:
                    nxt[j] += (v-1) / 2 
                    nxt[j+1] += (v-1) / 2 
            row = nxt 
        return min(1, row[query_glass])
# @lc code=end

