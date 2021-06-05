class Solution:
    def copyRandomList(self, head: 'Node') -> 'Node':
        if not head:
            return None
        cur = head
        # 1.复制各节点,构建拼接链表
        while cur:
            node = Node(cur.val)
            node.next = cur.next
            cur.next = node
            cur = node.next
        # 2.构建random指向
        cur = head
        while cur:
            if cur.random:
                cur.next.random = cur.random.next
            cur = cur.next.next
        # 3.拆分两个链表
        pre = head
        ans = cur = head.next
        while cur.next:
            pre.next = cur.next
            cur.next = cur.next.next
            pre = pre.next
            cur = cur.next
        pre.next = None
        return ans
