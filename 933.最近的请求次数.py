#
# @lc app=leetcode.cn id=933 lang=python3
#
# [933] 最近的请求次数
#

# @lc code=start
class RecentCounter:

    def __init__(self):
        self.que = deque()


    def ping(self, t: int) -> int:
        self.que.append(t)
        while self.que[0] < t - 3000:
            self.que.popleft()
        return len(self.que)


# Your RecentCounter object will be instantiated and called as such:
# obj = RecentCounter()
# param_1 = obj.ping(t)
# @lc code=end

