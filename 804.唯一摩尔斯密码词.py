#
# @lc app=leetcode.cn id=804 lang=python3
#
# [804] 唯一摩尔斯密码词
#

# @lc code=start
class Solution:
    def uniqueMorseRepresentations(self, words: List[str]) -> int:
        trans = [
            ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---",
            ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."
        ]
        st = set()
        for word in words:
            s = ""
            for c in word:
                s += trans[ord(c) - ord('a')]
            st.add(s)
        return len(st)

# @lc code=end

