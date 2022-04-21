#
# @lc app=leetcode.cn id=824 lang=python3
#
# [824] 山羊拉丁文
#

# @lc code=start
class Solution:
    def toGoatLatin(self, sentence: str) -> str:
        words = sentence.split()
        for i in range(len(words)):
            if words[i][0] not in 'aeiouAEIOU':
                words[i] = words[i][1:] + words[i][0]
            words[i] += 'ma' + 'a' * (i+1)
        return ' '.join(words)
# @lc code=end

