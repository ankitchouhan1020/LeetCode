class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        stack1 = []
        stack2 = []

        while l1:
            stack1.append(l1)
            l1 = l1.next

        while l2:
            stack2.append(l2)
            l2 = l2.next

        head = None
        carry = 0

        while carry or stack1 or stack2:
            carry += (stack1.pop().val if stack1 else 0) + \
                     (stack2.pop().val if stack2 else 0)
            node = ListNode(carry % 10)
            node.next = head
            head = node
            carry //= 10

        return head
