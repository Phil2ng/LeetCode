class MinStack:

    def __init__(self):
        self.stack = []
        self.minStk = []

    def push(self, x: int) -> None:
        self.stack.append(x)
        if not self.minStk:
            self.minStk.append(x)
        else:
            self.minStk.append(min(self.minStk[-1], x))

    def pop(self) -> None:
        self.stack.pop()
        self.minStk.pop()

    def top(self) -> int:
        return self.stack[-1]

    def min(self) -> int:
        return self.minStk[-1]

# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(x)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.min()
