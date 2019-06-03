class Solution:
    def nextLargerNodes(self, head: ListNode) -> List[int]:
        ans = []
        stack = []
        curr = head

        while curr:
            while stack and ans[stack[-1]] < curr.val:
                ans[stack[-1]] = curr.val
                stack.pop()
            stack.append(len(ans))
            ans.append(curr.val)
            curr = curr.next

        for i in stack:
            ans[i] = 0

        return ans
