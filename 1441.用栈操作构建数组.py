#
# @lc app=leetcode.cn id=1441 lang=python3
#
# [1441] 用栈操作构建数组
#

# @lc code=start
class Solution:
    def buildArray(self, target: List[int], n: int) -> List[str]:
        ans = []
        i, n, t = 0, len(target), 1
        while i < n:
            while target[i] != t:
                ans.append("Push")
                ans.append("Pop")
                t += 1
            ans.append("Push")
            t += 1
            i += 1
        return ans
# @lc code=end

