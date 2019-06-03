class Solution {
 public:
  int distinctSubseqII(string S) {
    vector<long> map(26);

    for (char c : S)
      map[c - 'a'] = accumulate(map.begin(), map.end(), 1L) % int(1e9 + 7);

    return accumulate(map.begin(), map.end(), 0L) % int(1e9 + 7);
  }
};