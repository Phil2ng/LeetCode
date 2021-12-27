#
# @lc app=leetcode.cn id=825 lang=python3
#
# [825] 适龄的朋友
#

# @lc code=start
class Solution:
    def numFriendRequests(self, ages: List[int]) -> int:
        ages.sort()
        ans = 0
        for i in range(len(ages)):
            left = bisect.bisect_right(ages, 0.5*ages[i]+7)
            if left>i:
                continue
            right = bisect.bisect_right(ages, ages[i])
            ans += right-1-left
        return ans
# @lc code=end

