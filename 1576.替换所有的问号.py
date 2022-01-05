#
# @lc app=leetcode.cn id=1576 lang=python3
#
# [1576] 替换所有的问号
#

# @lc code=start
class Solution:
    def modifyString(self, s: str) -> str:
        ans = list(s)
        for i in range(len(ans)):
            if ans[i] == '?':
                for x in 'abc':
                    if not (i>0 and ans[i-1]==x or i<len(ans)-1 and ans[i+1]==x):
                        ans[i] = x
                        break
        return ''.join(ans)

# @lc code=end

