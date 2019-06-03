class Solution {
 public:
  int maxAreaOfIsland(vector<vector<int>>& grid) {
    if (grid.empty()) return 0;

    const int m = grid.size();
    const int n = grid[0].size();

    int ans = 0;
    vector<vector<bool>> visited(m, vector<bool>(n));

    for (int i = 0; i < m; i++)
      for (int j = 0; j < n; j++) ans = max(ans, dfs(grid, i, j, visited));

    return ans;
  }

 private:
  int dfs(vector<vector<int>>& grid, int i, int j,
          vector<vector<bool>>& visited) {
    if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() ||
        visited[i][j] || grid[i][j] == 0)
      return 0;

    visited[i][j] = true;

    return dfs(grid, i + 1, j, visited) + dfs(grid, i - 1, j, visited) +
           dfs(grid, i, j + 1, visited) + dfs(grid, i, j - 1, visited) + 1;
  }
};