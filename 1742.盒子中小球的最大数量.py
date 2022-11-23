#
# @lc app=leetcode.cn id=1742 lang=python3
#
# [1742] 盒子中小球的最大数量
#

# @lc code=start
class Solution:
    def countBalls(self, lowLimit: int, highLimit: int) -> int:
        ans = 0
        cnt = defaultdict(int)  
        for x in range(lowLimit, highLimit + 1):
            t = 0 
            while x:
                t += x % 10 
                x //= 10 
            cnt[t] += 1
            ans = max(ans, cnt[t]) 
        return ans
# @lc code=end

