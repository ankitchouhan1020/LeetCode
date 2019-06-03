class Solution:
    def copyRandomList(self, head: 'Node') -> 'Node':
        if not head:
            return None
        if head in self.dict:
            return self.dict[head]

        self.dict[head] = Node(head.val, None, None)
        self.dict[head].next = self.copyRandomList(head.next)
        self.dict[head].random = self.copyRandomList(head.random)

        return self.dict[head]

    dict = {}
