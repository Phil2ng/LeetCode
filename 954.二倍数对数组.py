#
# @lc app=leetcode.cn id=954 lang=python3
#
# [954] 二倍数对数组
#

# @lc code=start
class Solution:
    def canReorderDoubled(self, arr: List[int]) -> bool:
        cnt = Counter(arr)
        if cnt[0] & 1:
            return False
        for i in sorted(cnt, key=abs):
            cnt[i * 2] -= cnt[i]
            if cnt[i * 2] < 0:
                return False
        return True
# @lc code=end

