class Solution:
    def uniquePathsWithObstacles(self, obstacleGrid: List[List[int]]) -> int:
        if not obstacleGrid or obstacleGrid[0][0]:
            return 0

        m = len(obstacleGrid)
        n = len(obstacleGrid[0])

        dp = [[0] * n for _ in range(m)]

        for i in range(m):
            for j in range(n):
                if i == 0 and j == 0:
                    dp[i][j] = 1
                elif i == 0 and not obstacleGrid[i][j]:
                    dp[i][j] = dp[i][j - 1]
                elif j == 0 and not obstacleGrid[i][j]:
                    dp[i][j] = dp[i - 1][j]
                elif not obstacleGrid[i][j]:
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1]

        return dp[m - 1][n - 1]
