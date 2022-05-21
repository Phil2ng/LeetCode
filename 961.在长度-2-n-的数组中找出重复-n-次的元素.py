#
# @lc app=leetcode.cn id=961 lang=python3
#
# [961] 在长度 2N 的数组中找出重复 N 次的元素
#

# @lc code=start
class Solution:
    def repeatedNTimes(self, nums: List[int]) -> int:
        n = len(nums)
        while True:
            x, y = random.randrange(n), random.randrange(n)
            if x != y and nums[x] == nums[y]:
                return nums[x]

# @lc code=end

