class Solution {
 public:
  int numMatchingSubseq(string S, vector<string>& words) {
    int ans = 0;

    vector<vector<int>> map(26);
    for (int i = 0; i < S.length(); i++) map[S[i] - 'a'].push_back(i);

    for (string& word : words) ans += isMatch(word, map);

    return ans;
  }

 private:
  unordered_map<string, bool> m;

  bool isMatch(string& word, vector<vector<int>>& map) {
    if (m.count(word)) return m[word];

    int prev = -1;

    for (char c : word) {
      vector<int>& p = map[c - 'a'];
      auto it = lower_bound(p.begin(), p.end(), prev + 1);
      if (it == p.end()) return m[word] = false;
      prev = *it;
    }

    return m[word] = true;
  }
};