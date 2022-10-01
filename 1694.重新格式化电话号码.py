#
# @lc app=leetcode.cn id=1694 lang=python3
#
# [1694] 重新格式化电话号码
#

# @lc code=start
class Solution:
    def reformatNumber(self, number: str) -> str:
        s = ""
        for c in number:
            if c != ' ' and c != '-':
                s += c
        ans = []
        i, n = 0, len(s)
        while n - i > 4:
            ans.append(s[i:i + 3])
            i += 3
        if n - i == 4:
            ans.append(s[i:i + 2])
            i += 2
        ans.append(s[i:])
        return '-'.join(ans)
# @lc code=end

