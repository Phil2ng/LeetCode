#
# @lc app=leetcode.cn id=720 lang=python3
#
# [720] 词典中最长的单词
#

# @lc code=start
class Trie:
    def __init__(self) -> None:
        self.children = defaultdict(Trie)
        self.isEnd = False
        self.word = ""

    def insert(self, word: str):
        node = self
        for c in word:
            node = node.children[c]
        node.isEnd = True
        node.word = word

    def isWord(self, word: str):
        node = self
        for c in word:
            if c not in node.children:
                return False
            node = node.children[c]
            if not node.isEnd:
                return False
        return True


class Solution:
    def longestWord(self, words: List[str]) -> str:
        trie = Trie()
        ans = ""
        for word in words:
            trie.insert(word)
        for word in words:
            if (len(ans) < len(word) or len(ans) == len(word)
                    and word < ans) and trie.isWord(word):
                ans = word
        return ans
# @lc code=end

