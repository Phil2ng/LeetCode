#
# @lc app=leetcode.cn id=884 lang=python3
#
# [884] 两句话中的不常见单词
#

# @lc code=start
class Solution:
    def uncommonFromSentences(self, s1: str, s2: str) -> List[str]:
        cnt1 = Counter(s1.split())
        cnt2 = Counter(s2.split())
        ans = []
        for k, v in cnt1.items():
            if v == 1 and k not in cnt2:
                ans.append(k)
        for k, v in cnt2.items():
            if v == 1 and k not in cnt1:
                ans.append(k)
        return ans
# @lc code=end

