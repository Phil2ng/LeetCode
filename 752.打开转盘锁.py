#
# @lc app=leetcode.cn id=752 lang=python3
#
# BFS广度优先搜索
#
# [752] 打开转盘锁
#

# @lc code=start
class Solution:
    def openLock(self, deadends: List[str], target: str) -> int:
        dead_st = set(deadends)
        if '0000' in dead_st:
            return -1

        def next_prev(num):
            return '9' if num == '0' else str(int(num)-1)

        def next_succ(num):
            return '0' if num == '9' else str(int(num)+1)

        def next_status(status):
            s = list(status)
            for i in range(4):
                num = s[i]
                s[i] = next_prev(num)
                yield ''.join(s)
                s[i] = next_succ(num)
                yield ''.join(s)
                s[i] = num

        que = collections.deque()
        que.append(("0000", 0))
        seen = {"0000"}
        while que:
            status, step = que.popleft()
            if status == target:
                return step
            for next in next_status(status):
                if next not in dead_st and next not in seen:
                    que.append((next, step+1))
                    seen.add(next)
        return -1
# @lc code=end
