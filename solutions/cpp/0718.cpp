class Solution {
 public:
  int findLength(vector<int>& A, vector<int>& B) {
    const int m = A.size();
    const int n = B.size();

    int ans = 0;
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (int i = m - 1; i >= 0; i--)
      for (int j = n - 1; j >= 0; j--)
        if (A[i] == B[j]) dp[i][j] = dp[i + 1][j + 1] + 1;

    for (vector<int>& row : dp)
      ans = max(ans, *max_element(row.begin(), row.end()));

    return ans;
  }
};