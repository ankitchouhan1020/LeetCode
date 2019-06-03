class Solution {
 public:
  vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
    const int n = A.size();

    for (vector<int>& row : A)
      for (int i = 0; i < (n + 1) / 2; i++) {
        int temp = row[i] ^ 1;
        row[i] = row[n - 1 - i] ^ 1;
        row[n - 1 - i] = temp;
      }

    return A;
  }
};