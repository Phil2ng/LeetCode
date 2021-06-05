# 大顶堆/小顶堆,优先队列

class MedianFinder:

    def __init__(self):
        self.A = []
        self.B = []

    def addNum(self, num: int) -> None:
        if len(self.A) == len(self.B):
            heapq.heappush(self.A, -heapq.heappushpop(self.B, -num))
        else:
            heapq.heappush(self.B, -heapq.heappushpop(self.A, num))

    def findMedian(self) -> float:
        if len(self.A) == len(self.B):
            return (self.A[0] - self.B[0])/2
        else:
            return self.A[0]
