# 数据结构-数组
# 无重复 and 最大值-最小值<5

class Solution:
    def isStraight(self, nums: List[int]) -> bool:
        cnt0 = nums.count(0)
        for _ in range(cnt0):
            nums.remove(0)
        return len(nums) == len(set(nums)) and max(nums)-min(nums) < 5
