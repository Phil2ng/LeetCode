#
# @lc app=leetcode.cn id=71 lang=python3
#
# [71] 简化路径
#

# @lc code=start
class Solution:
    def simplifyPath(self, path: str) -> str:
        names = path.split('/')
        stk = []
        for name in names:
            if name == '..':
                if stk:
                    stk.pop()
            elif name and name != '.':
                stk.append(name)
        return '/'+'/'.join(stk)

# @lc code=end

