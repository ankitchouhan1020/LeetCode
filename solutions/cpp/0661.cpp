class Solution {
 public:
  vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
    const int m = M.size();
    const int n = M[0].size();

    vector<vector<int>> ans(m, vector<int>(n));

    for (int i = 0; i < m; i++)
      for (int j = 0; j < n; j++) ans[i][j] = helper(M, i, j);

    return ans;
  }

 private:
  int helper(vector<vector<int>>& M, int x, int y) {
    int sum = 0;
    int count = 0;

    for (int i = -1; i <= 1; i++)
      for (int j = -1; j <= 1; j++) {
        if (x + i < 0 || x + i >= M.size() || y + j < 0 || y + j >= M[0].size())
          continue;
        count++;
        sum += M[x + i][y + j];
      }

    return sum / count;
  }
};
