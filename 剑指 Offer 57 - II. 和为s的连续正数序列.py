# 双指针

class Solution:
    def findContinuousSequence(self, target: int) -> List[List[int]]:
        fast, slow, sum = 3, 1, 3
        ans = []
        while True:
            sum += fast
            fast += 1
            while sum > target:
                sum -= slow
                slow += 1
            if fast-slow < 2:
                break
            if sum == target:
                ans.append(list(range(slow, fast, 1)))
        return ans
