class Solution {
 public:
  bool wordBreak(string s, vector<string>& wordDict) {
    unordered_set<string> set(wordDict.begin(), wordDict.end());
    return wordBreak(s, set);
  }

 private:
  unordered_map<string, bool> map;

  bool wordBreak(string& s, unordered_set<string>& set) {
    if (map.count(s)) return map[s];
    if (set.count(s)) return map[s] = true;

    for (int i = 1; i < s.length(); i++) {
      string left = s.substr(0, i);
      string right = s.substr(i);
      if (wordBreak(left, set) && set.count(right)) return map[s] = true;
    }

    return map[s] = false;
  }
};