# 数学规律

class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        ans, cnt = 0, 0
        for n in nums:
            if cnt == 0:
                ans = n
            if n == ans:
                cnt += 1
            else:
                cnt -= 1
        return ans
