class Solution:
    def validateStackSequences(self, pushed: List[int], popped: List[int]) -> bool:
        stack = []
        for s in pushed:
            stack.append(s)
            while stack and (stack[-1] == popped[0]):
                stack.pop()
                popped.pop(0)
        return True if not stack else False
