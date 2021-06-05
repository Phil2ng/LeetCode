class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Codec:

    def serialize(self, root: TreeNode):
        if not root:
            return '[]'
        data = []
        cur_stack = [root]
        while cur_stack:
            next_stack, tmp = [], []
            for node in cur_stack:
                if node:
                    tmp.append(str(node.val))
                    next_stack.append(node.left)
                    next_stack.append(node.right)
                else:
                    tmp.append("null")
            data.extend(tmp)
            cur_stack = next_stack
        return '['+','.join(data)+']'

    def deserialize(self, data: string):
        data = data[1:-1]
        if not data:
            return None
        data_list = data.split(',')
        root = TreeNode(int(data_list[0]))
        deque = collections.deque()
        deque.append(root)
        i = 1
        while deque:
            node = deque.popleft()
            if data_list[i] != 'null':
                node.left = TreeNode(int(data_list[i]))
                deque.append(node.left)
            i += 1
            if data_list[i] != 'null':
                node.right = TreeNode(int(data_list[i]))
                deque.append(node.right)
            i += 1
        return root
