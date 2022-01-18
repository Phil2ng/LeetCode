#
# @lc app=leetcode.cn id=539 lang=python3
#
# [539] 最小时间差
#

# @lc code=start
class Solution:
    def findMinDifference(self, timePoints: List[str]) -> int:
        n = len(timePoints)
        if n >= 24 * 60:
            return 0
        arr = [int(t[:2]) * 60 + int(t[3:5]) for t in timePoints]
        arr.sort()
        arr.append(arr[0] + 24 * 60)
        ans = 24 * 60
        for i in range(n):
            ans = min(ans, arr[i + 1] - arr[i])
        return ans
# @lc code=end

