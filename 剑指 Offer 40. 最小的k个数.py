# 快速选择

class Solution:
    def getLeastNumbers(self, arr: List[int], k: int) -> List[int]:
        if k == 0:
            return []
        self.quick_select(arr, 0, len(arr)-1, k)
        return arr[:k]

    def quick_select(self, arr, l, r, k):
        pos = self.random_partition(arr, l, r)
        num = pos-l+1
        if num > k:
            self.quick_select(arr, l, pos-1, k)
        elif num < k:
            self.quick_select(arr, pos+1, r, k-num)

    def random_partition(self, arr, l, r):
        i = random.randint(l, r)
        arr[r], arr[i] = arr[i], arr[r]
        return self.partition(arr, l, r)

    def partition(self, arr, l, r):
        pivot = arr[r]
        i = l
        for j in range(l, r):
            if arr[j] <= pivot:
                arr[i], arr[j] = arr[j], arr[i]
                i += 1
        arr[i], arr[r] = arr[r], arr[i]
        return i
