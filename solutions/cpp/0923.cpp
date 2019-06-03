class Solution {
 public:
  int threeSumMulti(vector<int>& A, int target) {
    long ans = 0;

    unordered_map<int, long> map;
    for (int a : A) map[a]++;

    for (auto& [i, x] : map)
      for (auto& [j, y] : map) {
        int k = target - i - j;
        if (!map.count(k)) continue;
        if (i == j && j == k)
          ans += x * (x - 1) * (x - 2) / 6;
        else if (i == j && j != k)
          ans += x * (x - 1) / 2 * map[k];
        else if (i < j && j < k)
          ans += x * y * map[k];
      }

    return ans % int(1e9 + 7);
  }
};