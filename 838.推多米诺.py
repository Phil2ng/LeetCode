#
# @lc app=leetcode.cn id=838 lang=python3
#
# [838] 推多米诺
#


# @lc code=start
class Solution:
    def pushDominoes(self, dominoes: str) -> str:
        n = len(dominoes)
        while True:
            new = list(dominoes)
            for i in range(n):
                if dominoes[i] == '.':
                    if i > 0 and dominoes[i - 1] == 'R' and i < n - 1 and dominoes[i + 1] == 'L':
                        continue
                    elif i > 0 and dominoes[i - 1] == 'R':
                        new[i] = 'R'
                    elif i < n - 1 and dominoes[i + 1] == 'L':
                        new[i] = 'L'
            new_dominoes = ''.join(new)
            if new_dominoes == dominoes:
                break
            dominoes = new_dominoes
        return dominoes


# @lc code=end
