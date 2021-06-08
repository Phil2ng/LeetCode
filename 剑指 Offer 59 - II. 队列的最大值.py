# 单调队列

class MaxQueue:

    def __init__(self):
        self.val = []
        self.max_val = []

    def max_value(self) -> int:
        if not self.max_val:
            return -1
        return self.max_val[0]

    def push_back(self, value: int) -> None:
        self.val.append(value)
        while self.max_val and self.max_val[-1] < value:
            self.max_val.pop()
        self.max_val.append(value)

    def pop_front(self) -> int:
        if not self.val:
            return -1
        value = self.val.pop(0)
        if self.max_val[0] == value:
            self.max_val.pop(0)
        return value
