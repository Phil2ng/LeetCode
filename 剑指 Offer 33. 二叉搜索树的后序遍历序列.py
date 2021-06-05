# bst性质, 辅助单调栈
# 递归

class Solution:
    def verifyPostorder(self, postorder: [int]) -> bool:
        stack, prev = [], float("+inf")
        for num in postorder[::-1]:
            if num > prev:
                return False
            while(stack and num < stack[-1]):
                prev = stack.pop()
            stack.append(num)
        return True

    def verifyPostorder(self, postorder: List[int]) -> bool:
        def recur(i, j):
            if i >= j:
                return True
            p = i
            while postorder[p] < postorder[j]:
                p += 1
            m = p
            while postorder[p] > postorder[j]:
                p += 1
            return p == j and recur(i, m-1) and recur(m, j-1)

        return recur(0, len(postorder)-1)
