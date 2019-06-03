class Solution {
 public:
  vector<vector<int>> spiralMatrixIII(int R, int C, int r0, int c0) {
    vector<vector<int>> ans = {{r0, c0}};
    int x = 0;
    int y = 1;

    for (int i = 0; ans.size() < R * C; i++) {
      for (int j = 0; j < i / 2 + 1; j++) {
        r0 += x;
        c0 += y;
        if (0 <= r0 && r0 < R && 0 <= c0 && c0 < C) ans.push_back({r0, c0});
      }
      swap(x, y);
      y *= -1;
    }

    return ans;
  }
};