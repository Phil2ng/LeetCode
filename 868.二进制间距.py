#
# @lc app=leetcode.cn id=868 lang=python3
#
# [868] 二进制间距
#


# @lc code=start
class Solution:
    def binaryGap(self, n: int) -> int:
        pre, i, ans = -1, 0, 0
        while n:
            if n & 1:
                if pre != -1:
                    ans = max(ans, i - pre)
                pre = i
            n >>= 1
            i += 1
        return ans


# @lc code=end
