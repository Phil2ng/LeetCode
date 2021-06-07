# 双指针

class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        dic = {}
        ans, pre = 0, -1
        for cur in range(len(s)):
            if s[cur] in dic:
                pre = max(pre, dic[s[cur]])
            ans = max(ans, cur-pre)
            dic[s[cur]] = cur
        return ans
