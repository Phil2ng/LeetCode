#
# @lc app=leetcode.cn id=436 lang=python3
#
# [436] 寻找右区间
#


# @lc code=start
class Solution:
    def findRightInterval(self, intervals: List[List[int]]) -> List[int]:
        n = len(intervals)
        arr = []
        idx = {}
        for i in range(n):
            arr.append(intervals[i][0])
            idx[arr[-1]] = i
        arr.sort()
        ans = []
        for a, b in intervals:
            t = bisect.bisect_left(arr, b)
            if t == n:
                ans.append(-1)
            else:
                ans.append(idx[arr[t]])
        return ans


# @lc code=end
