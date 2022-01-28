#
# @lc app=leetcode.cn id=1996 lang=python3
#
# [1996] 游戏中弱角色的数量
#

# @lc code=start
class Solution:
    def numberOfWeakCharacters(self, properties: List[List[int]]) -> int:
        properties.sort(key=lambda x: (-x[0], x[1]))
        ans, pmax = 0, 0
        for _, defense in properties:
            if defense < pmax:
                ans += 1
            else:
                pmax = max(pmax, defense)
        return ans

# @lc code=end

