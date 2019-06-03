class Solution:
    def reorderList(self, head: ListNode) -> None:
        if not head or not head.next:
            return

        prev = None
        slow = head
        fast = head
        l1 = head

        while fast and fast.next:
            prev = slow
            slow = slow.next
            fast = fast.next.next
        prev.next = None

        l2 = self.reverse(slow)
        self.merge(l1, l2)

    def reverse(self, head: ListNode) -> ListNode:
        prev = None
        curr = head

        while curr:
            next = curr.next
            curr.next = prev
            prev = curr
            curr = next

        return prev

    def merge(self, l1: ListNode, l2: ListNode) -> None:
        while l2:
            next = l1.next
            l1.next = l2
            l1 = l2
            l2 = next
