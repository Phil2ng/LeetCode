# 哈希表计数

class Solution:
    def firstUniqChar(self, s: str) -> str:
        dic = Counter(list(s))
        for c in s:
            if dic[c] == 1:
                return c
        return " "
