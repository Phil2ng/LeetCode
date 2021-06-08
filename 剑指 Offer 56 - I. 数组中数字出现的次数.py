# 位运算,分组异或

class Solution:
    def singleNumbers(self, nums: List[int]) -> List[int]:
        k = functools.reduce(lambda x, y: x ^ y, nums)
        t = k & (-k)
        ans1, ans2 = 0, 0
        for num in nums:
            if (num & t):
                ans1 ^= num
            else:
                ans2 ^= num
        return [ans1, ans2]
