#
# @lc app=leetcode.cn id=784 lang=python3
#
# [784] 字母大小写全排列
#


# @lc code=start
class Solution:
    def letterCasePermutation(self, s: str) -> List[str]:
        self.ans = []
        n = len(s)

        def dfs(step: int, t: str):
            if step == n:
                self.ans.append(t)
                return
            if s[step].isdigit():
                dfs(step + 1, t + s[step])
            else:
                dfs(step + 1, t + s[step].lower())
                dfs(step + 1, t + s[step].upper())

        dfs(0, "")
        return self.ans


# @lc code=end
