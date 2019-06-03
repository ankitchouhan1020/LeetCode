class Solution:
    def rob(self, root: TreeNode) -> int:
        return max(self.helper(root))

    def helper(self, root: TreeNode) -> List[int]:
        if not root:
            return 0, 0

        left = self.helper(root.left)
        right = self.helper(root.right)

        return max(left[0], left[1]) + max(right[0], right[1]), \
               root.val + left[0] + right[0]
