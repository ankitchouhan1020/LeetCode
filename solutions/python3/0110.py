class Solution:
    def isBalanced(self, root: TreeNode) -> bool:
        if not root:
            return True

        return abs(self.maxDepth(root.left) - self.maxDepth(root.right)) <= 1 and \
            self.isBalanced(root.left) and \
            self.isBalanced(root.right)

    def maxDepth(self, root: TreeNode) -> int:
        if not root:
            return 0

        return 1 + max(self.maxDepth(root.left), self.maxDepth(root.right))
