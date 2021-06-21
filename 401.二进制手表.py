#
# @lc app=leetcode.cn id=401 lang=python3
#
# [401] 二进制手表
#

# @lc code=start
class Solution:
    def readBinaryWatch(self, turnedOn: int) -> List[str]:
        ans = []
        for i in range(1024):
            h, m = i >> 6, i & 0x3f
            if h < 12 and m < 60 and bin(i).count('1') == turnedOn:
                ans.append(f"{h}:{m:02d}")
        return ans
# @lc code=end
