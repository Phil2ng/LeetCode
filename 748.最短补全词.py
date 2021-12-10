#
# @lc app=leetcode.cn id=748 lang=python3
#
# 模拟
#
# [748] 最短补全词
#

# @lc code=start
from typing import Counter, List


class Solution:
    def shortestCompletingWord(self, licensePlate: str, words: List[str]) -> str:
        cnt = Counter(c.lower() for c in licensePlate if c.isalpha())
        return min(word for word in words if not cnt-Counter(word), key=len)
# @lc code=end
