class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        if not grid:
            return 0

        m = len(grid)
        n = len(grid[0])

        ans = 0
        self.visited = [[False for j in range(len(grid[0]))]
                        for i in range(len(grid))]

        for i in range(m):
            for j in range(n):
                ans = max(ans, self.dfs(grid, i, j))

        return ans

    def dfs(self, grid: List[List[int]], i: int, j: int) -> int:
        if i < 0 or j < 0 or i >= len(grid) or j >= len(grid[0]) or self.visited[i][j] or grid[i][j] == 0:
            return 0

        self.visited[i][j] = True

        return self.dfs(grid, i + 1, j) + self.dfs(grid, i - 1, j) + \
               self.dfs(grid, i, j + 1) + self.dfs(grid, i, j - 1) + 1
