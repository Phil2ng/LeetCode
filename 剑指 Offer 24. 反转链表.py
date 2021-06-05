# 1.迭代
# 2.递归

class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        pHead = ListNode()
        while head:
            p = head.next
            head.next = pHead.next
            pHead.next = head
            head = p
        return pHead.next

    def reverseList(self, head: ListNode) -> ListNode:
        if not head or not head.next:
            return head
        pHead = self.reverseList(head.next)
        head.next.next = head
        head.next = None
        return pHead
