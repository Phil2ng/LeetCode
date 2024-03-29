#
# @lc app=leetcode.cn id=1700 lang=python3
#
# [1700] 无法吃午餐的学生数量
#

# @lc code=start
class Solution:
    def countStudents(self, students: List[int], sandwiches: List[int]) -> int:
        cnt = Counter(students)
        n = len(sandwiches)
        for i, x in enumerate(sandwiches):
            if cnt[x] <= 0:
                return n - i
            cnt[x] -= 1
        return 0
# @lc code=end

