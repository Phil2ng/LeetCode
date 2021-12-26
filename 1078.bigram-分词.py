#
# @lc app=leetcode.cn id=1078 lang=python3
#
# 遍历
# [1078] Bigram 分词
#

# @lc code=start
class Solution:
    def findOcurrences(self, text: str, first: str, second: str) -> List[str]:
        words = text.split()
        return [
            words[i] for i in range(2, len(words))
            if words[i - 2] == first and words[i - 1] == second
        ]
# @lc code=end

