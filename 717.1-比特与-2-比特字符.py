#
# @lc app=leetcode.cn id=717 lang=python3
#
# [717] 1比特与2比特字符
#


# @lc code=start
class Solution:
    def isOneBitCharacter(self, bits: List[int]) -> bool:
        t, i = 0, len(bits) - 2
        if bits[-1] == 0:
            while bits[i]:
                t += 1
                i -= 1
            if t % 2 == 0:
                return True
        return False


# @lc code=end
