#
# @lc app=leetcode.cn id=278 lang=python3
#
# [278] 第一个错误的版本
#

# @lc code=start
# The isBadVersion API is already defined for you.
# @param version, an integer
# @return an integer
# def isBadVersion(version):


class Solution:
    def firstBadVersion(self, n):
        first, len = 0, n
        while len > 0:
            half = len >> 1
            mid = first+half
            if isBadVersion(mid+1):
                len = half
            else:
                first = mid+1
                len -= half+1
        return first+1

# @lc code=end
