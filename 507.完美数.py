#
# @lc app=leetcode.cn id=507 lang=python3
#
# [507] 完美数
#

# @lc code=start
class Solution:
    def checkPerfectNumber(self, num: int) -> bool:
        if num == 1:
            return False
        psum = 1
        for i in range(2, int(math.sqrt(num))+1):
            if num % i == 0:
                psum += i 
                if num != i*i:
                    psum += num//i
        return psum == num
# @lc code=end

