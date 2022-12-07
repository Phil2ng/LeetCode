#
# @lc app=leetcode.cn id=1775 lang=python3
#
# [1775] 通过最少操作次数使数组的和相等
#

# @lc code=start
class Solution:
    def minOperations(self, nums1: List[int], nums2: List[int]) -> int:
        def helper(a: List[int], b: List[int]):
            suma, sumb = sum(a), sum(b)
            if suma < sumb:
                return helper(b, a)  
            m, n = len(a), len(b)
            i, j = m - 1, 0
            ret = 0
            while suma >= sumb:
                if suma == sumb:
                    return ret
                if i < 0 and j >= n:
                    return -1
                if j >= n or i >= 0 and a[i] - 1 >= 6 - b[j]:
                    suma -= a[i] - 1
                    a[i] = 1
                    i -= 1
                else:
                    sumb += 6 - b[j]
                    b[j] = 6
                    j += 1
                ret += 1
            return ret

        nums1.sort()
        nums2.sort()
        return helper(nums1, nums2)
# @lc code=end

