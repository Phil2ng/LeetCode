#
# @lc app=leetcode.cn id=1640 lang=python3
#
# [1640] 能否连接形成数组
#

# @lc code=start
class Solution:
    def canFormArray(self, arr: List[int], pieces: List[List[int]]) -> bool:
        index = {p[0]: i for i, p in enumerate(pieces)}
        i, n = 0, len(arr)
        while i < n:
            if arr[i] not in index:
                return False
            j = index[arr[i]]
            for k in range(len(pieces[j])):
                if arr[i] != pieces[j][k]:
                    return False
                i += 1
        return True
# @lc code=end

