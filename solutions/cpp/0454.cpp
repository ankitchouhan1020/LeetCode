class Solution {
 public:
  int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C,
                   vector<int>& D) {
    int ans = 0;
    unordered_map<int, int> map;

    for (int a : A)
      for (int b : B) map[a + b]++;

    for (int c : C)
      for (int d : D) ans += map.count(-c - d) ? map[-c - d] : 0;

    return ans;
  }
};