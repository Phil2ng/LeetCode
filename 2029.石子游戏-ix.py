#
# @lc app=leetcode.cn id=2029 lang=python3
#
# [2029] 石子游戏 IX
#

# @lc code=start
class Solution:
    def stoneGameIX(self, stones: List[int]) -> bool:
        cnt = [0] * 3
        for val in stones:
            cnt[val % 3] += 1
        if cnt[0] % 2 == 0:
            return cnt[1] > 0 and cnt[2] > 0
        return cnt[1] - cnt[2] > 2 or cnt[2] - cnt[1] > 2
# @lc code=end

