#
# @lc app=leetcode.cn id=1345 lang=python3
#
# [1345] 跳跃游戏 IV
#

# @lc code=start
class Solution:
    def minJumps(self, arr: List[int]) -> int:
        n = len(arr)
        same = defaultdict(list)
        seen = [False] * n
        for i, v in enumerate(arr):
            same[v].append(i)
        que = deque([(0, 0)])
        seen[0] = True
        while que:
            i, step = que.popleft()
            if i == n - 1:
                return step
            step += 1
            for j in same[arr[i]]:
                if not seen[j]:
                    que.append((j, step))
                    seen[j] = True
            same[arr[i]] = []
            if i > 0 and not seen[i - 1]:
                que.append((i - 1, step))
                seen[i - 1] = True
            if i < n and not seen[i + 1]:
                que.append((i + 1, step))
                seen[i + 1] = True

# @lc code=end

