class Solution:
    def removeElements(self, head: ListNode, val: int) -> ListNode:
        dummy = ListNode(None)
        dummy.next = head
        curr = dummy

        while curr:
            next = curr.next
            while next and next.val == val:
                next = next.next
            curr.next = next
            curr = next

        return dummy.next
