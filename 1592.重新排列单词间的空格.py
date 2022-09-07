#
# @lc app=leetcode.cn id=1592 lang=python3
#
# [1592] 重新排列单词间的空格
#

# @lc code=start
class Solution:
    def reorderSpaces(self, text: str) -> str:
        words = text.split()
        cnt = text.count(' ')
        if len(words) == 1:
            return words[0] + ' ' * cnt
        per, rest = divmod(cnt, len(words) - 1)
        return (' ' * per).join(words) + ' ' * rest
# @lc code=end

