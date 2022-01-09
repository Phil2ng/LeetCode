#
# @lc app=leetcode.cn id=1629 lang=python3
#
# [1629] 按键持续时间最长的键
#


# @lc code=start
class Solution:
    def slowestKey(self, releaseTimes: List[int], keysPressed: str) -> str:
        pmax = releaseTimes[0]
        pchar = keysPressed[0]
        for i in range(len(releaseTimes) - 1):
            tmp = releaseTimes[i + 1] - releaseTimes[i]
            if tmp > pmax or tmp == pmax and ord(
                    keysPressed[i + 1]) > ord(pchar):
                pmax = tmp
                pchar = keysPressed[i + 1]
        return pchar


# @lc code=end
