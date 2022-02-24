#
# @lc app=leetcode.cn id=1706 lang=python3
#
# [1706] 球会落何处
#

# @lc code=start
class Solution:
    def findBall(self, grid: List[List[int]]) -> List[int]:
        m, n = len(grid), len(grid[0]) if grid else 0
        ans = [-1] * n
        for t in range(n):
            j = t
            for i in range(m):
                d = grid[i][j]
                j += d
                if j == -1 or j == n or grid[i][j] != d:
                    break
            else:
                ans[t] = j
        return ans
# @lc code=end

