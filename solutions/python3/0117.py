class Solution:
    def connect(self, root: 'Node') -> 'Node':
        node = root
        curr = Node(None, None, None, None)
        prev = curr

        while node:
            while node:
                curr.next = node.left
                curr = curr.next or curr
                curr.next = node.right
                curr = curr.next or curr
                node = node.next
            node = prev.next
            curr = prev

        return root
