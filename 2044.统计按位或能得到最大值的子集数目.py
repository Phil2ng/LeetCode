#
# @lc app=leetcode.cn id=2044 lang=python3
#
# [2044] 统计按位或能得到最大值的子集数目
#

# @lc code=start
class Solution:
    def countMaxOrSubsets(self, nums: List[int]) -> int:
        pmax = reduce(or_, nums, 0)
        n = len(nums)
        self.ans = 0

        def dfs(step: int, psum: int):
            if step == n:
                if psum == pmax:
                    self.ans += 1
                return
            dfs(step + 1, psum)
            dfs(step + 1, psum | nums[step])

        dfs(0, 0)
        return self.ans
# @lc code=end

