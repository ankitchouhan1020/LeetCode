class Solution:
    def connect(self, root: 'Node') -> 'Node':
        node = root

        while node and node.left:
            next = node.left
            while node:
                node.left.next = node.right
                node.right.next = node.next and node.next.left
                node = node.next
            node = next

        return root
