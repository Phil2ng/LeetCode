#
# @lc app=leetcode.cn id=1282 lang=python3
#
# [1282] 用户分组
#

# @lc code=start
class Solution:
    def groupThePeople(self, groupSizes: List[int]) -> List[List[int]]:
        groups = defaultdict(list)
        for i, size in enumerate(groupSizes):
            groups[size].append(i)
        ans = []
        for size, people in groups.items():
            ans.extend(people[i: i + size] for i in range(0, len(people), size))
        return ans

# @lc code=end

