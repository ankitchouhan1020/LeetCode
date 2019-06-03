class Solution {
 public:
  int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    if (obstacleGrid.empty() || obstacleGrid[0][0]) return 0;

    const int m = obstacleGrid.size();
    const int n = obstacleGrid[0].size();

    vector<vector<long>> dp(m, vector<long>(n));

    for (int i = 0; i < m; i++)
      for (int j = 0; j < n; j++) {
        if (i == 0 && j == 0)
          dp[i][j] = 1;
        else if (i == 0 && !obstacleGrid[i][j])
          dp[i][j] = dp[i][j - 1];
        else if (j == 0 && !obstacleGrid[i][j])
          dp[i][j] = dp[i - 1][j];
        else if (!obstacleGrid[i][j])
          dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
      }

    return dp[m - 1][n - 1];
  }
};