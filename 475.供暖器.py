#
# @lc app=leetcode.cn id=475 lang=python3
#
# [475] 供暖器
#

# @lc code=start
class Solution:
    def findRadius(self, houses: List[int], heaters: List[int]) -> int:
        houses.sort()
        heaters.sort()
        ans = 0
        n = len(heaters)
        i = 0
        for house in houses:
            cur = abs(house - heaters[i])
            while i + 1 < n and abs(house - heaters[i]) >= abs(house - heaters[i + 1]):
                i += 1
                cur = abs(house - heaters[i])
            ans = max(ans, cur)
        return ans
# @lc code=end

