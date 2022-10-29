#
# @lc app=leetcode.cn id=1773 lang=python3
#
# [1773] 统计匹配检索规则的物品数量
#

# @lc code=start
class Solution:
    def countMatches(self, items: List[List[str]], ruleKey: str, ruleValue: str) -> int:
        index = {"type": 0, "color": 1, "name": 2}[ruleKey]
        return sum(item[index] == ruleValue for item in items)
# @lc code=end

