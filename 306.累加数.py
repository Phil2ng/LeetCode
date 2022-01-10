#
# @lc app=leetcode.cn id=306 lang=python3
#
# [306] 累加数
#

# @lc code=start
class Solution:
    def isAdditiveNumber(self, num: str) -> bool:
        n = len(num)

        def dfs(a: int, b: int, s: str):
            if not s:
                return True
            total = str(a + b)
            if total == s[:len(total)]:
                return dfs(b, a + b, s[len(total):])
            else:
                return False

        for i in range(1, n):
            if num[0] == '0' and i > 1:
                break
            for j in range(i + 1, n):
                if num[i] == '0' and j - i > 1:
                    break
                if dfs(int(num[:i]), int(num[i:j]), num[j:]):
                    return True
        return False
# @lc code=end

