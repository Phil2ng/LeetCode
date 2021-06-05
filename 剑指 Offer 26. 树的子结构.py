#  递归判断子结构

# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
class Solution:
    def isSubStructure(self, A: TreeNode, B: TreeNode) -> bool:
        if not B:
            return False

        def isSame(A, B):
            if not B:
                return True
            if not A:
                return False
            return (A.val == B.val) and isSame(A.left, B.left) and isSame(A.right, B.right)

        def isSubStruct(A, B):
            if not A:
                return False
            return isSame(A, B) or isSubStruct(A.left, B) or isSubStruct(A.right, B)

        return isSubStruct(A, B)
