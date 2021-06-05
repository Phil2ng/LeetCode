# DP动态规划

class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        # ans, sum = float("-inf"), 0
        # for num in nums:
        #     sum = max(sum, 0)
        #     sum += num
        #     ans = max(ans, sum)
        # return ans
        for i in range(1, len(nums)):
            nums[i] += max(nums[i-1], 0)
        return max(nums)
