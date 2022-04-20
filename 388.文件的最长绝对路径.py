#
# @lc app=leetcode.cn id=388 lang=python3
#
# [388] 文件的最长绝对路径
#

# @lc code=start
class Solution:
    def lengthLongestPath(self, input: str) -> int:
        input += '\n'
        ans, i, l, cnt, n = 0, 0, 0, 0, len(input)
        level = []
        isFile = False
        while i < n:
            if input[i] == '\n':
                if l < len(level):
                    level[l] = cnt
                else:
                    level.append(cnt)
                if isFile:
                    ans = max(ans, l + sum(level[:l + 1]))
                cnt = l = 0
                isFile = False
            elif input[i] == '\t':
                l += 1
            else:
                cnt += 1
                if input[i] == '.':
                    isFile = True
            i += 1
        return ans
# @lc code=end

