#
# @lc app=leetcode.cn id=2016 lang=python3
#
# [2016] 增量元素之间的最大差值
#

# @lc code=start
class Solution:
    def maximumDifference(self, nums: List[int]) -> int:
        pmin = inf
        ans = -1
        for x in nums:
            if x > pmin:
                ans = max(ans, x - pmin)
            elif x < pmin:
                pmin = x
        return ans
# @lc code=end

