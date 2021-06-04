# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def deleteNode(self, head: ListNode, val: int) -> ListNode:
        begin = ListNode(0)
        begin.next = head
        pre = begin
        while(pre.next.val != val):
            pre = pre.next
        pre.next = pre.next.next
        return begin.next
