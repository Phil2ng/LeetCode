#
# @lc app=leetcode.cn id=1447 lang=python3
#
# [1447] 最简分数
#

# @lc code=start
class Solution:
    def simplifiedFractions(self, n: int) -> List[str]:
        return [f"{numerator}/{denominator}" for denominator in range(2, n + 1) for numerator in range(1, denominator) if gcd(denominator, numerator) == 1]
# @lc code=end

