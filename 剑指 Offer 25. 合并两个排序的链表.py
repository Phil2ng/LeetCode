# 链表双指针

class Solution:
    def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:
        pHead = ListNode()
        p = pHead
        while l1 and l2:
            if l1.val <= l2.val:
                p.next = l1
                p = l1
                l1 = l1.next
            else:
                p.next = l2
                p = l2
                l2 = l2.next
        p.next = l1 if l1 else l2
        return pHead.next
