#
# @lc app=leetcode.cn id=2024 lang=python3
#
# [2024] 考试的最大困扰度
#

# @lc code=start
class Solution:
    def maxConsecutiveAnswers(self, answerKey: str, k: int) -> int:
        ans = left = right = cntT = cntF = 0
        n = len(answerKey)
        while right < n:
            if answerKey[right] == 'T':
                cntT += 1
            else:
                cntF += 1
            while left < right and (cntT > k and cntF > k):
                if answerKey[left] == 'T':
                    cntT -= 1
                else:
                    cntF -= 1
                left += 1
            ans = max(ans, right - left + 1)
            right += 1
        return ans
# @lc code=end

