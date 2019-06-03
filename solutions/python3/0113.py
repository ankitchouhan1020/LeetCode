class Solution:
    def pathSum(self, root: TreeNode, sum: int) -> List[List[int]]:
        ans = []

        self.dfs(root, sum, [], ans)

        return ans

    def dfs(self, root: TreeNode, sum: int, path: List[int], ans: List[List[int]]) -> None:
        if not root:
            return
        if sum == root.val and not root.left and not root.right:
            ans.append(path + [root.val])
            return

        self.dfs(root.left, sum - root.val, path + [root.val], ans)
        self.dfs(root.right, sum - root.val, path + [root.val], ans)
