class Solution:
    def sortedListToBST(self, head: ListNode) -> TreeNode:
        def helper(l, r):
            nonlocal head

            if l > r:
                return None

            mid = (l + r) >> 1

            left = helper(l, mid - 1)
            node = TreeNode(head.val)
            head = head.next
            node.left = left
            node.right = helper(mid + 1, r)

            return node

        length = 0
        curr = head
        while curr:
            length += 1
            curr = curr.next

        return helper(0, length - 1)
