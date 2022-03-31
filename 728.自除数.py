#
# @lc app=leetcode.cn id=728 lang=python3
#
# [728] 自除数
#

# @lc code=start
class Solution:
    def selfDividingNumbers(self, left: int, right: int) -> List[int]:
        def helper(x :int):
            a = x
            while a:
                a, t = divmod(a, 10)
                if not t or x % t:
                    return False
            return True

        ans = []
        for x in range(left, right+1):
            if helper(x):
                ans.append(x)
        return ans
# @lc code=end

